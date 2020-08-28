#ifndef Cube_H
#define Cube_H


#include "Node.h"
#include "NodeExtestions.h"

namespace GLSandbox
{

	class Texture2D;
	class ShaderProgram;
	class Cube 
		: public Node
		, public MaterialProtocol
	{
		typedef Node Parent;
	

		Texture2D* _texture;
		ShaderProgram* _shader;

		std::vector<GLfloat> _vertices;
		std::vector<GLuint> _indices;

		GLuint _vbo;
		GLuint _vao;
		GLuint _ebo;

	protected:

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		Cube();
		virtual ~Cube();
		MAKE_UNCOPYABLE(Cube);

		bool initWithFilePath( const std::string& filePath );

		void setShaderProgram( ShaderProgram* program );
		void setTexture( Texture2D* texture );
	};


}


#endif