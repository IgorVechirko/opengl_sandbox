#include "Point.h"

#include "ShadersCache.h"
#include "DrawTypes.h"
#include "GLContext.h"
#include "Scene.h"
#include "ShaderProgram.h"

namespace GLSandbox
{

	Point::Point()
		: _size( 1.0f )
	{
	}
	Point::~Point()
	{
	}
	bool Point::onInit()
	{
		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
		_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0 );

		setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::POS_UCOLOR_ROUND_POINT ) );

		std::vector<PosVertex> vertices = { {Vec3(0.0f)} };
		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices.data(), sizeof(PosVertex), vertices.size() );

		return true;
	}
	void Point::draw( const Mat4& transform )
	{
		if ( _shader )
		{
			_shader->useProgram();

			auto scene = getGLContext()->getScene();

			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );
			scene->setViewToShader( _shader );
			scene->setProjectionToShader( _shader );

			_shader->setUniform4f( "u_color", _color.r, _color.g, _color.b, _color.a );			

			glPointSize(_size);
			
			_arrayBuffer.drawArrays( GL_POINTS, 0 );
		}
	}
	void Point::setSize( float radius )
	{
		_size = radius;
	}
	float Point::getSize() const
	{
		return _size;
	}


}