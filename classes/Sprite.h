#ifndef Sprite_H
#define Sprite_H


#include "Node.h"

namespace GLSandbox
{

	class Texture2D;
	class ShaderProgram;
	class Sprite : public Node
	{
		typedef Node Parent;
	

		Texture2D* _texture;
		ShaderProgram* _shader;

		std::vector<GLfloat> _vertices;
		std::vector<GLuint> _indices;

		GLuint _vbo;
		GLuint _vao;
		GLuint _ebo;

		void updateVertices( const Size& size );

	protected:

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		Sprite();
		virtual ~Sprite();

		bool initWithFilePath( const std::string& filePath );

		void setShaderProgram( ShaderProgram* program );
		void setTexture( Texture2D* texture );
	};


}


#endif