#include "Model.h"

#include "DrawTypes.h"
#include "Texture2D.h"
#include "GLContext.h"
#include "Scene.h"
#include "ShaderProgram.h"



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
		_meshes.resize( node->mNumMeshes );

		for( unsigned int meshIndx = 0; meshIndx < node->mNumMeshes; meshIndx++ )
		{
			auto mesh = scene->mMeshes[ node->mMeshes[meshIndx]];
			
			auto& meshInfo = _meshes[meshIndx];
			meshInfo.arrayObject.genBuffer( VertexArrayObject::BufferType::VERTEX );
			meshInfo.arrayObject.genBuffer( VertexArrayObject::BufferType::ELEMENT );
			meshInfo.arrayObject.setupAttribPointer( 0, 3, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)0 );
			meshInfo.arrayObject.setupAttribPointer( 1, 2, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)(3*sizeof(GLfloat)) );
			meshInfo.arrayObject.setupAttribPointer( 2, 3, GL_FLOAT, false, sizeof(PosUVNormalVertex), (GLvoid*)(5*sizeof(GLfloat)) );


			std::vector<PosUVNormalVertex> vertices( mesh->mNumVertices );

			float _cubeSize = 100.0f;
			
			for( unsigned int vertIndx = 0; vertIndx < mesh->mNumVertices; vertIndx++ )
			{
				auto& vertex = vertices[vertIndx];
				vertex.pos = Vec3( mesh->mVertices[vertIndx].x, mesh->mVertices[vertIndx].y, mesh->mVertices[vertIndx].z );
				vertex.normal = Vec3( mesh->mNormals[vertIndx].x, mesh->mNormals[vertIndx].y, mesh->mNormals[vertIndx].z );

				if ( mesh->mTextureCoords[0] )
				{
					vertex.uv = Vec( mesh->mTextureCoords[0][vertIndx].x, mesh->mTextureCoords[0][vertIndx].y );
				}
				else
				{
					vertex.uv = Vec( 0.0f );
				}
			}

			meshInfo.arrayObject.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices.data(), sizeof(PosUVNormalVertex), vertices.size() );

			std::vector<GLuint> indices;

			for( unsigned int i = 0; i < mesh->mNumFaces; i++ )
			{
				const auto& face = mesh->mFaces[i];
				for( unsigned int j = 0; j < face.mNumIndices; j++ )
				{
					indices.push_back( face.mIndices[j] );
				}
			}

			meshInfo.arrayObject.setupBufferData( VertexArrayObject::BufferType::ELEMENT, indices.data(), sizeof(GLuint), indices.size() );


			{
				aiMaterial* material = scene->mMaterials[ mesh->mMaterialIndex ];

				if( material->GetTextureCount( aiTextureType_DIFFUSE ) > 0 )
				{
					aiString str;
					material->GetTexture( aiTextureType_DIFFUSE, 0, &str );
					auto texture = createRefWithInitializer<Texture2D>(&Texture2D::initWithFilePath, directory + "/" + str.C_Str() );
					
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
					auto texture = createRefWithInitializer<Texture2D>(&Texture2D::initWithFilePath, directory + "/" + str.C_Str() );
					
					if ( texture )
					{
						texture->retain();
						meshInfo.specularMap = texture;
					}
				}
			}
		}

	
		for( unsigned int nodeIndx = 0; nodeIndx < node->mNumChildren; nodeIndx++ )
		{
			auto subMode = createNode<Model>();
			addProtectedChild( subMode );
			_subModels.push_back( subMode );
			subMode->processModelSceneTree( node->mChildren[nodeIndx], scene, directory );
		}
	}
	void Model::setShaderProgram( ShaderProgram* shader )
	{
		ShaderProtocol::setShaderProgram( shader );

		for( auto subModel : _subModels )
			subModel->setShaderProgram( shader );
	}
	void Model::visit( GLRender* render, const Mat4& parentTransform )
	{
		Node::visit( render, parentTransform );

		auto transform = getTransform() * parentTransform;
		visitProtectedChilds( render, transform );
	}
	void Model::draw( GLRender* render, const Mat4& transform )
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
}