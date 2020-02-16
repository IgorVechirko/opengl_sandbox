#ifndef Mesh_H
#define Mesh_H

#include "VECommon.h"

_VESTART

class ShaderProgram;
class Mesh
{

	std::vector<PosNormaTextCordVertex> _vertices;
	std::vector<unsigned int> _indices;
	std::vector<Texture> _textures;


	GLuint _vao;
	GLuint _vbo;
	GLuint _ebo;

	Mesh();

	void setupMesh();

	std::string getTextureTypeStrFromEnum( eTextureType type );

public:
	
		Mesh( const std::vector<PosNormaTextCordVertex>& vetrices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures );
		virtual ~Mesh();


		void draw( ShaderProgram* shader, const Mat4& transform );

};



_VEEND



#endif
