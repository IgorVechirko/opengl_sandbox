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

			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );
			_shader->setUniformMatrix4fv( "u_view", 1, false, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			_shader->setUniformMatrix4fv( "u_projection", 1, false, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );
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