#ifndef Sprite_H
#define Sprite_H


#include "Node.h"
#include "NodeExtensions.h"

namespace GLSandbox
{
	class Sprite 
		: public Node
		, public ShaderProtocol
		, public Texture2DProtocol
			
	{
		typedef Node Parent;

		std::vector<GLfloat> _vertices;
		std::vector<GLuint> _indices;

		GLuint _vbo;
		GLuint _vao;
		GLuint _ebo;


	protected:

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		Sprite();
		virtual ~Sprite();
		MAKE_UNCOPYABLE(Sprite);

		bool initWithFilePath( const std::string& filePath );

		virtual void setTexture2D( Texture2D* texture ) override;

	};


}


#endif