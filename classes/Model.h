#ifndef Model_H
#define Model_H

#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


namespace GLSandbox
{

	class Model
		: public Node
		, public ShaderProtocol
		, public MaterialProtocol
	{

		struct Mesh
		{
			VertexArrayObject arrayObject;
			Texture2D* diffuseMap;
			Texture2D* specularMap;

			std::string name;

			Mesh()
				: diffuseMap( nullptr )
				, specularMap( nullptr )
			{}
		};


		std::vector<Model*> _subModels;
		std::vector<Mesh> _meshes;


		void processModelSceneTree( aiNode* node, const aiScene* scene, const std::string& directory );

		void processMeshVertices( Mesh& meshInfo, const aiMesh* processingMesh );
		void processMeshIndices( Mesh& meshInfo, const aiMesh* processingMesh );
		void processMeshMaterial( Mesh& meshInfo, const aiMesh* processingMesh, const aiScene* scene, const std::string& directory );


	public:

		Model();
		virtual ~Model();

		bool initWithFilePath( const std::string& filePath );

		virtual void setShaderProgram( ShaderProgram* shader ) override;

		virtual void draw( GLRender* resnder, const Mat4& transform ) override; 

		const std::vector<Model*>& getSubModels();

	};



}



#endif