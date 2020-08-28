#include "Model.h"



namespace GLSandbox
{


	Model::Model()
	{
	}
	Model::~Model()
	{
	}
	void Model::loadModel( const std::string& path )
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile( path, aiProcess_Triangulate | aiProcess_FlipUVs );

		//if ( !scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mRootNode )
		{
			//LOG( "ERROR::ASSIMP::%s", importer.GetErrorString() );
			//return;
		}
		_directory = path.substr( 0, path.find_last_of( '/' ) );

		processNode( scene->mRootNode, scene );
	}
	void Model::processNode( aiNode* node, const aiScene* scene )
	{
		for( unsigned int i = 0; i < node->mNumMeshes; i++ )
		{
			aiMesh* mesh = scene->mMeshes[ node->mMeshes[i]];
			_meshes.push_back( processMesh( mesh, scene ) );
		}
	
		for( unsigned int i = 0; i < node->mNumChildren; i++ )
		{
			processNode(node->mChildren[i], scene);
		}
	}
	Mesh Model::processMesh( aiMesh* mesh, const aiScene* scene )
	{
		std::vector<PosNormaTextCordVertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		for( unsigned int i = 0; i < mesh->mNumVertices; i++ )
		{
			PosNormaTextCordVertex vertex;
			vertex.pos = Vec3( mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z );
			vertex.normal = Vec3( mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z );

			if ( mesh->mTextureCoords[0] )
			{
				vertex.textCord = glm::vec2( mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y );
			}
			else
			{
				vertex.textCord = glm::vec2( 0.0f );
			}
		
			vertices.push_back( vertex );
		}

		for( unsigned int i = 0; i < mesh->mNumFaces; i++ )
		{
			aiFace face = mesh->mFaces[i];
			for( unsigned int j = 0; j < face.mNumIndices; j++ )
			{
				indices.push_back( face.mIndices[j] );
			}
		}

		if (mesh->mMaterialIndex >= 0 )
		{
			aiMaterial* material = scene->mMaterials[ mesh->mMaterialIndex ];

			std::vector<Texture> diffuseMaps = loadMatertialTextures( material, aiTextureType_DIFFUSE, eTextureType::DIFFUSE_LIHGT_MAP );
			textures.insert( textures.end(), diffuseMaps.begin(), diffuseMaps.end() );

			std::vector<Texture> specularMaps = loadMatertialTextures( material, aiTextureType_SPECULAR, eTextureType::SPECULAR_LIHGT_MAP );
			textures.insert( textures.begin(), specularMaps.begin(), specularMaps.end() );
		}

		return Mesh( getScope(), vertices, indices, textures );
	}
	std::vector<Texture> Model::loadMatertialTextures( aiMaterial* mat, aiTextureType type, eTextureType textureType )
	{
		std::vector<Texture> result;
		result.resize( mat->GetTextureCount(type) );
	
		for( unsigned int i = 0; i < mat->GetTextureCount(type); i++ )
		{
			aiString str;
			mat->GetTexture( type, i, &str );
			Texture& texture = result[ i ];
			texture.id = textureFromFile(str.C_Str(), _directory);
			texture.type = textureType;
		}

		return result;
	}
	GLuint Model::textureFromFile( const char* path, const std::string& directory )
	{
		unsigned int result = 0;

		std::string filename = directory + '/' + std::string(path);

		glGenTextures(1, &result);

		int width, height, nrComponents;
		unsigned char* image = SOIL_load_image( filename.c_str(), &width, &height, &nrComponents, 0 );
	
		if (image)
		{
			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, result);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			SOIL_free_image_data(image);
			glBindTexture( GL_TEXTURE_2D, 0 );
		}
		else
		{
			//LOG( "Texture failed to load at path: %s", filename.c_str() );
			SOIL_free_image_data(image);
		}

		return result;
	}
	void Model::draw( GLRender* render, const Mat4& transform )
	{
		for( auto& mesh : _meshes )
		{
			mesh.draw( getShaderProgram(), transform );
		}
	}

}