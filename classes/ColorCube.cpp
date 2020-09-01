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
		, _verticesDirty( true )
	{
		setColor( RGBA::WHITE );
	}
	ColorCube::~ColorCube()
	{
	}
	void ColorCube::updateVertices()
	{
		PosVertex vertices[] = { Vec3( 0.0f, 0.0f, 0.0f ),
								 Vec3( 0.0f, _cubeSize, 0.0f ),
								 Vec3( _cubeSize, 0.0f, 0.0f ),
								 Vec3( _cubeSize, _cubeSize, 0.0f ),
								 Vec3( 0.0f, 0.0f, _cubeSize ),
								 Vec3( 0.0f, _cubeSize, _cubeSize ),
								 Vec3( _cubeSize, 0.0f, _cubeSize ),
								 Vec3( _cubeSize, _cubeSize, _cubeSize )
		};

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosVertex), sizeof(vertices)/sizeof(PosVertex) );
	}
	bool ColorCube::onInit()
	{
		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::ELEMENT );
		_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, false, 0, (GLvoid*)0 );

		auto shader = createRefWithInitializer<ShaderProgram>( &ShaderProgram::initWithSrc, getResMng()->getResStr( "VERTEX_POS_UCOLOR_VSH" ), getResMng()->getResStr( "VERTEX_POS_UCOLOR_FSH" ) );

		if ( shader )
			setShaderProgram( shader );

		GLuint indices[] = { 0, 1, 2, 1, 2, 3,
							 4, 5, 6, 5, 6, 7,
							 2, 3, 6, 3, 6, 7,
							 0, 1, 4, 1, 4, 5,
							 0, 4, 2, 4, 2, 6,
							 1, 5, 3, 5, 3, 7
		};

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::ELEMENT, indices, sizeof(GLuint), sizeof(indices)/sizeof(GLuint) );

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

		_arrayBuffer.drawElements( GL_TRIANGLES, GL_UNSIGNED_INT, 0 );
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