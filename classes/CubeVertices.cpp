#include "CubeVertices.h"


_USEVE


CubeVertices::CubeVertices()
	: _vao( 0 )
	, _vbo( 0 )
	, _verticesDirty( false )
{
	
}
CubeVertices::~CubeVertices()
{
	glDeleteVertexArrays( 1, &_vao );
}
void CubeVertices::updateVertices()
{	
}
void CubeVertices::setSize3( const Size3& size )
{
	if ( getSize3() != size )
	{
		_verticesDirty = true;
	}

	Size3Protocol::setSize3( size );
}