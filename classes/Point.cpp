#include "Line.h"


_USEVE

Line::Line()
{
}
Line::~Line()
{
}
void Line::actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	vertices.clear();
	indices.clear();

	Vertex begin(getPosition(), getColor());
	Vertex end(getEndPoint(), getColor());

	std::vector<Vertex> structurVertices{ begin, end };

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
	indices.push_back(1);
}
GLenum Line::getDrawElement()
{
	return GL_LINES;
}
void Line::setEndPoint( const Vec& end )
{
	_endPoint = end;
}
const Vec& Line::getEndPoint()
{
	return _endPoint;
}
