#ifndef Mesh_H
#define Mesh_H

#include "VECommon.h"
#include "WorkingScopeProvider.h"

namespace GLSandbox
{

	class ShaderProgram;
	class Mesh 
		: public WorkingScopeProvider
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
	
			Mesh( WorkingScope* scope, const std::vector<PosNormaTextCordVertex>& vetrices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures );
			virtual ~Mesh();


			void draw( ShaderProgram* shader, const Mat4& transform );

	};



}



#endif
