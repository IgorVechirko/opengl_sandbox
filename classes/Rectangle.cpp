#include "Rectangle.h"


_USEVE

Rectangle::Rectangle()
{
}
Rectangle::~Rectangle()
{
}
void Rectangle::actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	vertices.clear();
	indices.clear();

	Vertex topLeft( getPosition() + Vec( 0.0f, _size.y ), getColor());
	Vertex bottomLeft(getPosition(), getColor());
	Vertex topRight( getPosition() + _size, getColor());
	Vertex bottomRight( getPosition() + Vec( _size.x, 0.0f ), getColor());

	std::vector<Vertex> structurVertices{ topLeft, bottomLeft, topRight, bottomRight };

	for( const auto& structureVertex : structurVertices )
	{
		vertices.push_back(structureVertex._pos.x);
		vertices.push_back(structureVertex._pos.y);
		vertices.push_back(1.0f);
		
		vertices.push_back(structureVertex._color._r);
		vertices.push_back(structureVertex._color._g);
		vertices.push_back(structureVertex._color._b);
		vertices.push_back(structureVertex._color._a);
	}


	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
}
GLenum Rectangle::getDrawElement()
{
	return GL_TRIANGLES;
}
void Rectangle::setSize(const Size& size)
{
	_size = size;
	setVerticesDirty(true);
}
const Size& Rectangle::getSize()
{
	return _size;
}