#ifndef Model_H
#define Model_H

#include "Mesh.h"
#include "Node.h"
#include "NodeExtentions.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


_VESTART


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

	Model();

	virtual void draw( GLRender* render, const Mat4& transform ) override;


public:

	virtual ~Model();

	void draw( ShaderProgram* shader );

	CREATE_FUNC( Model );

	void loadModel( const std::string& path );

};



_VEEND



#endif