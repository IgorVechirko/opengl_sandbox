#ifndef Model_H
#define Model_H

#include "Mesh.h"
#include "Node.h"
#include "NodeExtensions.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


namespace GLSandbox
{


	class ShaderProgram;
	class Model : public Node
				, public ShaderProtocol
	{
		typedef Node Parent;

		std::vector<Mesh> _meshes;
		std::string _directory;


		void processNode( aiNode* node, const aiScene* scene );
		Mesh processMesh( aiMesh* mesh, const aiScene* scene );
		std::vector<Texture> loadMatertialTextures( aiMaterial* mao, aiTextureType type, eTextureType textureType );

		GLuint textureFromFile( const char* path, const std::string& directory );

	private: 

		virtual void draw( GLRender* render, const Mat4& transform ) override;


	public:

		Model();
		virtual ~Model();
		MAKE_UNCOPYABLE( Model );

		void loadModel( const std::string& path );

	};



}



#endif