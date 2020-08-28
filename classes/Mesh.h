#ifndef Mesh_H
#define Mesh_H

#include "Common.h"
#include "WorkingScopeProvider.h"

namespace GLSandbox
{

	struct PosNormaTextCordVertex
	{
		Vec3 pos;
		Vec3 normal;
		glm::vec2 textCord;
	};

	enum class eTextureType
	{
		NONE,
		DIFFUSE_LIHGT_MAP,
		SPECULAR_LIHGT_MAP
	};

	struct Texture
	{
		GLint id;
		eTextureType type;

		Texture()
			: id( 0 )
			, type( eTextureType::NONE )
		{
		}
	};

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
