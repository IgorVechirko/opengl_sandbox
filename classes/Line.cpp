#include "Line.h"

#include "ShaderProgram.h"
#include "ResourcesManager.h"
#include "Camera.h"
#include "Scene.h"
#include "GLContext.h"
#include "DrawTypes.h"


namespace GLSandbox
{

	Line::Line()
		: _verticesDirty( false )
		, _startPos( 0.0f )
		, _finishPos( 0.0f )
	{
		setColor( RGBA::WHITE );
	}
	Line::~Line()
	{
	}
	void Line::updateVertices()
	{
		PosVertex vertices[] = { { Vec3( _startPos.x, _startPos.y, _startPos.z ) },
								 { Vec3( _finishPos.x, _finishPos.y, _finishPos.z ) } };

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosVertex), sizeof(vertices)/sizeof(PosVertex) );
	}
	bool Line::onInit()
	{
		auto shader = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionUColor_vert, positionUColor_frag );
		setShaderProgram( shader );

		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
		_arrayBuffer.setupAttribPointer(0, 3, GL_FLOAT, false, 0, (GLvoid*)0 );

		updateVertices();

		return true;
	}
	void Line::draw( GLRender* render, const Mat4& parentTransform )
	{
		if ( _verticesDirty )
		{
			updateVertices();

			_verticesDirty = false;
		}

		if ( _shader )
		{
			_shader->useProgram();

			auto modelLoc = glGetUniformLocation( _shader->getProgramID(), "u_model" );
			auto viewLoc = glGetUniformLocation( _shader->getProgramID(), "u_view" );
			auto projectionLoc = glGetUniformLocation( _shader->getProgramID(), "u_projection" );
			auto colorLoc = glGetUniformLocation( _shader->getProgramID(), "u_color" );

			glProgramUniformMatrix4fv( _shader->getProgramID(), modelLoc, 1, GL_FALSE, glm::value_ptr(parentTransform) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), viewLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), projectionLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );
			glProgramUniform4f( _shader->getProgramID(), colorLoc, _color.r, _color.g, _color.b, _color.a );
		}

		_arrayBuffer.drawArrays( GL_LINE_STRIP, 0 );
	} 
	void Line::setStartPos( const Vec3& pos )
	{
		if ( _startPos != pos )
		{
			_startPos = pos;
			_verticesDirty = true;
		}
	}
	const Vec3& Line::getStartPos() const
	{
		return _startPos;
	}
	void Line::setFinishPos( const Vec3& pos )
	{
		if ( _finishPos != pos )
		{
			_finishPos = pos;
			_verticesDirty = true;
		}
	}
	const Vec3& Line::getFinishPos() const
	{
		return _finishPos;
	}

}