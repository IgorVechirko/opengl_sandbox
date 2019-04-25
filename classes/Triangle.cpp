#include "Triangle.h"


_USEVE

Triangle::Triangle()
{
}
Triangle::~Triangle()
{
}
void Triangle::actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices)
{
	vertices.clear();
	indices.clear();

	Vertex point1(_point1, getColor());
	Vertex point2(_point2, getColor());
	Vertex posPoint(getPosition(), getColor());

	std::vector<Vertex> structurVertices{ point1, point2, posPoint };

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
}
GLenum Triangle::getDrawElement()
{
	return GL_TRIANGLES;
}
void Triangle::setPoints(const Vec& point1, const Vec& point2)
{
	_point1 = point1;
	_point2 = point2;
}
const Vec& Triangle::getPoint1()
{
	return _point1;
}
const Vec& Triangle::getPoint2()
{
	return _point2;
}