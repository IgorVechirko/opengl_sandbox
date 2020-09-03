#include "Sprite.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Scene.h"
#include "GLContext.h"
#include "ShadersCache.h"
#include "TexturesCache.h"

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

		auto texture = getTexturesCache()->createTexture2D( filePath );

		if ( texture )
		{
			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::ELEMENT );

			setTexture2D( texture );

			setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::POS_UV_TEXTURE ) );

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
	void Sprite::draw( const Mat4& transform )
	{
		if( getTexture2D() )
			getTexture2D()->useTexture();

		if( _shader )
		{
			_shader->useProgram();
			auto scene = getGLContext()->getScene();

			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );
			scene->setViewToShader( _shader );
			scene->setProjectionToShader( _shader );
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