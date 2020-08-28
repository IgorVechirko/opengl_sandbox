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
		, _vao( 0 )
		, _vbo( 0 )
	{
		setColor( RGBA::WHITE );
	}
	Line::~Line()
	{
	}
	void Line::updateVertices()
	{
		std::vector<PosVertex> vertices( 3 );
		vertices[0].pos = Vec3( _startPos.x, _startPos.y, _startPos.z );
		vertices[1].pos = Vec3( _finishPos.x, _finishPos.y, _finishPos.z );

		glBindVertexArray( _vao );
	
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(PosVertex)*2, (void*)(&vertices[0]) );
		glBindBuffer( GL_ARRAY_BUFFER, 0 );

		glBindVertexArray( 0 );
	}
	bool Line::onInit()
	{
		auto shader = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, getResMng()->getResStr( "VERTEX_POS_UCOLOR_VSH" ), getResMng()->getResStr( "VERTEX_POS_UCOLOR_FSH" ) );

		if ( shader )
			setShaderProgram( shader );

		glGenVertexArrays( 1, &_vao );
		glGenBuffers( 1, &_vbo );

		glBindVertexArray( _vao );

		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBufferData( GL_ARRAY_BUFFER, sizeof(PosVertex)*2, nullptr, GL_STATIC_DRAW );

		glVertexAttribPointer( 0, 3, GL_FLOAT, false, 0, (GLvoid*)0 );
		glEnableVertexAttribArray(0);

		glBindBuffer( GL_ARRAY_BUFFER, 0 );
		glBindVertexArray( 0 );

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

			auto modelLoc = glGetUniformLocation( _shader->getProgramID(), "model" );
			auto viewLoc = glGetUniformLocation( _shader->getProgramID(), "view" );
			auto projectionLoc = glGetUniformLocation( _shader->getProgramID(), "projection" );
			auto colorLoc = glGetUniformLocation( _shader->getProgramID(), "color" );

			glProgramUniformMatrix4fv( _shader->getProgramID(), modelLoc, 1, GL_FALSE, glm::value_ptr(parentTransform) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), viewLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), projectionLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );
			glProgramUniform4f( _shader->getProgramID(), colorLoc, _color.r, _color.g, _color.b, _color.a );
		}

		glBindVertexArray( _vao );
		glDrawArrays( GL_LINE_STRIP, 0, 2 );
		glBindVertexArray( 0 );

	}
	void Line::setStartPos( const Vec3& pos )
	{
		if ( _startPos != pos )
		{
			_startPos = pos;
			_verticesDirty = true;
		}
	}
	const Vec3& Line::getStartPos()
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
	const Vec3& Line::getFinishPos()
	{
		return _finishPos;
	}

}