#ifndef Cube_H
#define Cube_H


#include "Node.h"

_VESTART


class Texture2D;
class ShaderProgram;
class Cube : public Node
{
	typedef Node Parent;
	

	Texture2D* _texture;
	ShaderProgram* _shader;

	std::vector<GLfloat> _vertices;
	std::vector<GLuint> _indices;

	GLuint _vbo;
	GLuint _vao;
	GLuint _ebo;

	Material _material;

	void updateVertices( const Size& size );

protected:

	Cube();

	bool init( const std::string& filePath );

	virtual void draw( GLRender* render, const Mat4& transform ) override;

public:

	virtual ~Cube();

	static Cube* create( WorkingScope* scope, const std::string& filePath );

	void setShaderProgram( ShaderProgram* program );
	void setTexture( Texture2D* texture );

	void setMaterial( const Material& material );
	const Material& getMaterial();
};


_VEEND


#endif