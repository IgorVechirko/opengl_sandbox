#include "ColorCube.h"


#include "ShaderProgram.h"
#include "Camera.h"
#include "Scene.h"
#include "ResourcesManager.h"
#include "GLContext.h"
#include "DrawTypes.h"

namespace GLSandbox
{


	ColorCube::ColorCube()
		: _cubeSize( 1.0f )
		, _verticesDirty( false )
		, _vao( 0 )
		, _vbo( 0 )
		, _ebo( 0 )
		, _indicesCount( 0 )
	{
		setColor( RGBA::WHITE );
	}
	ColorCube::~ColorCube()
	{
	}
	void ColorCube::updateVertices()
	{
		std::vector<PosVertex> vertices( 8 );

		vertices[0].pos = Vec3( 0.0f, 0.0f, 0.0f );
		vertices[1].pos = Vec3( 0.0f, _cubeSize, 0.0f );
		vertices[2].pos = Vec3( _cubeSize, 0.0f, 0.0f );
		vertices[3].pos = Vec3( _cubeSize, _cubeSize, 0.0f );
		vertices[4].pos = Vec3( 0.0f, 0.0f, _cubeSize );
		vertices[5].pos = Vec3( 0.0f, _cubeSize, _cubeSize );
		vertices[6].pos = Vec3( _cubeSize, 0.0f, _cubeSize );
		vertices[7].pos = Vec3( _cubeSize, _cubeSize, _cubeSize );

		glBindVertexArray( _vao );
	
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(PosVertex) * 8, (void*)&vertices[0] );

		glBindBuffer( GL_ARRAY_BUFFER, 0 );
		glBindVertexArray( 0 );
	}
	bool ColorCube::onInit()
	{
		auto shader = createRefWithInitializer<ShaderProgram>( &ShaderProgram::initWithSrc, getResMng()->getResStr( "VERTEX_POS_UCOLOR_VSH" ), getResMng()->getResStr( "VERTEX_POS_UCOLOR_FSH" ) );

		if ( shader )
			setShaderProgram( shader );

		GLuint indices[] = { 0, 1, 2, 1, 2, 3,
						  4, 5, 6, 5, 6, 7,
						  2, 3, 6, 3, 6, 7,
						  0, 1, 4, 1, 4, 5,
						  0, 4, 2, 4, 2, 6,
						  1, 5, 3, 5, 3, 7 };
		_indicesCount = sizeof( indices ) / sizeof( int );

		glGenVertexArrays( 1, &_vao );
		glGenBuffers( 1, &_vbo );
		glGenBuffers( 1, &_ebo );

		glBindVertexArray( _vao );
	
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBufferData( GL_ARRAY_BUFFER, sizeof(PosVertex) * 8, nullptr, GL_STATIC_DRAW );

		glVertexAttribPointer( 0, 3, GL_FLOAT, false, 0, (GLvoid*)0 );
		glEnableVertexAttribArray(0);

		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, _indicesCount * sizeof(GLuint), (void*)&indices[0], GL_STATIC_DRAW );

		glBindBuffer( GL_ARRAY_BUFFER, 0 );
		glBindVertexArray( 0 );

		updateVertices();

		return true;
	}
	void ColorCube::draw( GLRender* render, const Mat4& parentTransform )
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
		glDrawElements( GL_TRIANGLES, _indicesCount, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
	}
	void ColorCube::setCubeSize( float size )
	{
		if ( size > 0.0f && abs(_cubeSize - size) > FLT_EPSILON  )
		{
			_cubeSize = size;
			_verticesDirty = true;
		}
	}

}