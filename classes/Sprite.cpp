#include "Sprite.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "ResourcesManager.h"
#include "Scene.h"
#include "Camera.h"
#include "GLContext.h"
#include "DrawTypes.h"

namespace GLSandbox
{

	Sprite::Sprite()
	{
	}
	Sprite::~Sprite()
	{
	}
	bool Sprite::initWithFilePath( const std::string& filePath )
	{	
		Node::init();

		auto texture = createRefWithInitializer<Texture2D>(&Texture2D::initWithFilePath, filePath );

		if ( texture )
		{
			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::ELEMENT );

			setTexture2D( texture );

			setShaderProgram( createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionUVTexture_vert, positionUVTexture_frag ) );

			GLuint indices[] = { 0, 1, 2,
								 1, 2, 3 };

			_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::ELEMENT, indices, sizeof(unsigned int), sizeof(indices)/sizeof(GLuint) );

			_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)0 );
			_arrayBuffer.setupAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)(3*sizeof(GLfloat)) );

			return true;
		}
		else
			return false;
	}
	void Sprite::draw( GLRender* render, const Mat4& transform )
	{
		if( getTexture2D() )
			glBindTexture( GL_TEXTURE_2D, getTexture2D()->getTextureID() );

		if( _shader )
		{
			_shader->useProgram();

			GLuint modelLoc = glGetUniformLocation( _shader->getProgramID(), "u_model" );
			GLuint viewLoc = glGetUniformLocation( _shader->getProgramID(), "u_view" );
			GLuint projectionLoc = glGetUniformLocation( _shader->getProgramID(), "u_projection" );

			glProgramUniformMatrix4fv( _shader->getProgramID(), modelLoc, 1, GL_FALSE, glm::value_ptr(transform) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), viewLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), projectionLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );

			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		}

		_arrayBuffer.drawElements( GL_TRIANGLES, GL_UNSIGNED_INT, 0 );
	}
	void Sprite::setTexture2D( Texture2D* texture )
	{
		Texture2DProtocol::setTexture2D( texture );

		if ( texture )
		{

			Size textSize( static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()) );

			PosUVVertex vertices[] = { { Vec3(0.0f, textSize.y, 0.0f ), Vec2( 0.0f, 0.0f ) },
									   { Vec3( 0.0f, 0.0f, 0.0f ), Vec2( 0.0f, 1.0f ) },
									   { Vec3( textSize.x, textSize.y, 0.0f ), Vec2( 1.0f, 0.0f ) },
								   	   { Vec3( textSize.x, 0.0f, 0.0f ), Vec2( 1.0f, 1.0f ) }
			};
			
			_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosUVVertex), sizeof(vertices)/sizeof(PosUVVertex) );
		}
	}

}