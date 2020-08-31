#include "Sprite.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "ResourcesManager.h"
#include "Scene.h"
#include "Camera.h"
#include "GLContext.h"

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
			setTexture2D( texture );

			setShaderProgram( createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, getResMng()->getResStr("SPRITE_VERTEX"), getResMng()->getResStr("SPRITE_FRAGMENT") ) );

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

			GLuint modelLoc = glGetUniformLocation( _shader->getProgramID(), "model" );
			GLuint viewLoc = glGetUniformLocation( _shader->getProgramID(), "view" );
			GLuint projectionLoc = glGetUniformLocation( _shader->getProgramID(), "projection" );

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

			std::vector<float>vertices = { 0.0f, textSize.y, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
										    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
										    textSize.x, textSize.y, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
										    textSize.x, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };

			std::vector<unsigned int>indices = { 0, 1, 2,
												  1, 2, 3 };

			
			_arrayBuffer.setupVBOData( vertices.data(), vertices.size()*sizeof(float) );
			_arrayBuffer.setupEBOdata( indices );

			_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)0 );
			_arrayBuffer.setupAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(3*sizeof(GL_FLOAT)) );
			_arrayBuffer.setupAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(6*sizeof(GL_FLOAT)) );
		}
	}

}