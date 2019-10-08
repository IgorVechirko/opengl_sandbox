#include "Primitive.h"

#include "Director.h"
#include "ShaderProgram.h"

_USEVE

Primitive::Primitive()
	: _program( nullptr )
	, _verticesDirty(true)
	, _vao(0)
	, _vbo(0)
	, _ebo(0)
	, _position(0.0f,0.0f)
{
	_program = ShaderProgram::create( RES_PATH("VERTES_SHADER"), RES_PATH("FRAGMENT_SHADER" ) );
	if ( _program )
	{
		_program->retain();
	}

	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);
	glGenBuffers(1, &_ebo);
}
Primitive::~Primitive()
{
	if ( _program )
	{
		_program->release();
	}

	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(2, &_ebo);
}
void Primitive::fillBuffers()
{
	glBindVertexArray(_vao);

	const GLfloat* vertices = &_vertices[0];
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*_vertices.size(), vertices, GL_STATIC_DRAW);

	const GLuint* indices = &_indices[0];
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*_indices.size(), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}
void Primitive::actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
}
void Primitive::setVerticesDirty( bool isDirty )
{
	_verticesDirty = isDirty;
}
bool Primitive::isVerticesDirty()
{
	return _verticesDirty;
}
void Primitive::setPosition(const Vec& position)
{
	_position = position;
}
const Vec& Primitive::getPosition()
{
	return _position;
}
void Primitive::setColor(const RGBA& color)
{
	_color = color;
}
const RGBA& Primitive::getColor()
{
	return _color;
}
void Primitive::draw()
{
	if (_verticesDirty)
	{
		actualizeVertices(_vertices, _indices);
		fillBuffers();

		_verticesDirty = false;
	}

	if ( _program )
		glUseProgram(_program->getProgramID());

	glBindVertexArray(_vao);

	glDrawElements(getDrawElement(), _indices.size(), GL_UNSIGNED_INT, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindVertexArray(0);
}