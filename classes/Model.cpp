#include "Model.h"

#include "DrawTypes.h"
#include "Texture2D.h"
#include "GLContext.h"
#include "Scene.h"
#include "ShaderProgram.h"
#include "TexturesCache.h"



namespace GLSandbox
{

	Model::Model()
	{
	}
	Model::~Model()
	{
		for( auto& mesh : _meshes )
		{
			if (mesh.diffuseMap)
			{
				mesh.diffuseMap->release();
				mesh.diffuseMap = nullptr;
			}

			if (mesh.specularMap)
			{
				mesh.specularMap->release();
				mesh.specularMap = nullptr;
			}
		}
	}
	bool Model::initWithFilePath( const std::string& filePath )
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile( filePath, aiProcess_Triangulate | aiProcess_FlipUVs );

		if ( !scene )
		{
			Console::log( "ERROR::ASSIMP::", importer.GetErrorString() );
			return false;
		}
		std::string directory = filePath.substr( 0, filePath.find_last_of( '/' ) );

		processModelSceneTree( scene->mRootNode, scene, directory );
		
		setShaderProgram( createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, posUVNormalLightProp_vert, posUVNormalLightProp_frag ) );

		return true;
	}
	void Model::processModelSceneTree( aiNode* node, const aiScene* scene, const std::string& directory )
	{
		setName( node->mName.C_Str() );

		_meshes.resize( node->mNumMeshes );

		for( unsigned int meshIndx = 0; meshIndx < node->mNumMeshes; meshIndx++ )
		{
			auto mesh = scene->mMeshes[ node->mMeshes[meshIndx]];
			auto& meshInfo = _meshes[meshIndx];

			meshInfo.name = mesh->mName.C_Str();

			meshInfo.arrayObject.genBuffer( VertexArrayObject::BufferType::VERTEX );
			meshInfo.arrayObject.genBuffer( VertexArrayObject::BufferType::ELEMENT );
			meshInfo.arrayObject.setupAttribPointer( 0, 3, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)0 );
			meshInfo.arrayObject.setupAttribPointer( 1, 2, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)(3*sizeof(GLfloat)) );
			meshInfo.arrayObject.setupAttribPointer( 2, 3, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)(5*sizeof(GLfloat)) );

			processMeshVertices( meshInfo, mesh );
			processMeshIndices( meshInfo, mesh );
			processMeshMaterial( meshInfo, mesh, scene, directory );
		}

	
		for( unsigned int nodeIndx = 0; nodeIndx < node->mNumChildren; nodeIndx++ )
		{
			auto subMode = createNode<Model>();
			addChild( subMode );
			_subModels.push_back( subMode );
			subMode->processModelSceneTree( node->mChildren[nodeIndx], scene, directory );
		}
	}
	void Model::processMeshVertices( Mesh& meshInfo, const aiMesh* processingMesh )
	{
		if ( processingMesh )
		{
			std::vector<PosUVNormalVertex> vertices( processingMesh->mNumVertices );
			
			for( unsigned int vertIndx = 0; vertIndx < processingMesh->mNumVertices; vertIndx++ )
			{
				auto& vertex = vertices[vertIndx];
				vertex.pos = Vec3( processingMesh->mVertices[vertIndx].x, processingMesh->mVertices[vertIndx].y, processingMesh->mVertices[vertIndx].z );
				vertex.normal = Vec3( processingMesh->mNormals[vertIndx].x, processingMesh->mNormals[vertIndx].y, processingMesh->mNormals[vertIndx].z );

				if ( processingMesh->mTextureCoords[0] )
				{
					vertex.uv = Vec( processingMesh->mTextureCoords[0][vertIndx].x, processingMesh->mTextureCoords[0][vertIndx].y );
				}
				else
				{
					vertex.uv = Vec( 0.0f );
				}
			}

			meshInfo.arrayObject.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices.data(), sizeof(PosUVNormalVertex), vertices.size() );
		}
	}
	void Model::processMeshIndices( Mesh& meshInfo, const aiMesh* processingMesh )
	{
		if ( processingMesh )
		{
			std::vector<GLuint> indices;

			for( unsigned int i = 0; i < processingMesh->mNumFaces; i++ )
			{
				const auto& face = processingMesh->mFaces[i];
				for( unsigned int j = 0; j < face.mNumIndices; j++ )
				{
					indices.push_back( face.mIndices[j] );
				}
			}

			meshInfo.arrayObject.setupBufferData( VertexArrayObject::BufferType::ELEMENT, indices.data(), sizeof(GLuint), indices.size() );
		}
	}
	void Model::processMeshMaterial( Mesh& meshInfo, const aiMesh* processingMesh, const aiScene* scene, const std::string& directory )
	{
		if ( processingMesh && scene )
		{
			aiMaterial* material = scene->mMaterials[ processingMesh->mMaterialIndex ];

			if( material->GetTextureCount( aiTextureType_DIFFUSE ) > 0 )
			{
				aiString str;
				material->GetTexture( aiTextureType_DIFFUSE, 0, &str );
				auto texture = getTexturesCache()->createTexture2D( directory + "/" + str.C_Str() );
					
				if ( texture )
				{
					texture->retain();
					meshInfo.diffuseMap = texture;
				}
			}

			if (  material->GetTextureCount( aiTextureType_SPECULAR ) > 0 )
			{
				aiString str;
				material->GetTexture( aiTextureType_SPECULAR, 0, &str );
				auto texture = getTexturesCache()->createTexture2D( directory + "/" + str.C_Str() );
					
				if ( texture )
				{
					texture->retain();
					meshInfo.specularMap = texture;
				}
			}
		}
	}
	void Model::setShaderProgram( ShaderProgram* shader )
	{
		ShaderProtocol::setShaderProgram( shader );

		for( auto subModel : _subModels )
			subModel->setShaderProgram( shader );
	}
	void Model::draw( const Mat4& transform )
	{
		for( auto& mesh : _meshes )
		{
			if ( _shader )
			{
				_shader->useProgram();
				auto scene = getGLContext()->getScene();

				_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr(transform) );
				scene->setProjectionToShader( _shader );
				scene->setViewToShader( _shader );

				scene->setCameraPosToShader( _shader );
				scene->setDirectLightPropToShader( _shader );
				scene->setPointLightsPropToShader( _shader );
				scene->setFlashLightsPropToShader( _shader );

				_shader->setMaterialUniforms( getMaterial(), "u_material", "ambient", "diffuse", "specular", "shininess" );
				_shader->setUniform1i( "u_diffText", 0 );
				_shader->setUniform1i( "u_specText", 1 );
			}

			if ( mesh.diffuseMap )
			{
				mesh.diffuseMap->useTexture(0);
			}
			else
			{
				glActiveTexture( GL_TEXTURE0 );
				glBindTexture( GL_TEXTURE_2D, 0 );
			}

			if ( mesh.specularMap )
			{
				mesh.specularMap->useTexture(1);
			}
			else
			{
				glActiveTexture( GL_TEXTURE1 );
				glBindTexture( GL_TEXTURE_2D, 0 );
			}

			mesh.arrayObject.drawElements( GL_TRIANGLES, GL_UNSIGNED_INT, 0 );
		}
	}
	const std::vector<Model*>& Model::getSubModels()
	{
		return _subModels;
	}
}