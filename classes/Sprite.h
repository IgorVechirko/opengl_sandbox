#ifndef Sprite_H
#define Sprite_H


#include "Node.h"

_VESTART


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

	Sprite();

	bool init( const std::string& filePath );

	virtual void draw( GLRender* render, const Mat4& transform ) override;

public:

	virtual ~Sprite();

	static Sprite* create( const std::string& filePath );

	void setShaderProgram( ShaderProgram* program );
	void setTexture( Texture2D* texture );
};


_VEEND


#endif