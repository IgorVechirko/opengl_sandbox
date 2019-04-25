#include "Point.h"


_USEVE

Point::Point()
{
}
Point::~Point()
{
}
void Point::actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	vertices.clear();
	indices.clear();

	Vertex begin(getPosition(), getColor());

	std::vector<Vertex> structurVertices{ begin };

	for( auto& structureVertex : structurVertices )
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
}
GLenum Point::getDrawElement()
{
	return GL_POINTS;
}
