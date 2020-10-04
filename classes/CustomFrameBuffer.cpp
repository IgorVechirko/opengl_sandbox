#include "CustomFrameBuffer.h"

#include "GLContext.h"
#include "OpenGL.h"
#include "DrawTypes.h"
#include "ShaderProgram.h"
#include "ShadersCache.h"

namespace GLSandbox
{

	CustomFrameBuffer::CustomFrameBuffer()
		: _fbo( 0 )
		, _colorBuffer( 0 )
		, _depthStencilBuffer( 0 )
	{
	}
	CustomFrameBuffer::~CustomFrameBuffer()
	{
		glDeleteRenderbuffers( 1, &_depthStencilBuffer );
		glDeleteTextures( 1, &_colorBuffer );
		glDeleteFramebuffers( 1, &_fbo );
	}
	bool CustomFrameBuffer::onInit()
	{
		bool result = true;

		auto& winSize = getGLContext()->getWindowSize();

		glGenFramebuffers( 1, &_fbo );
		glBindFramebuffer( GL_FRAMEBUFFER, _fbo );

		glGenTextures(1, &_colorBuffer);
		glBindTexture( GL_TEXTURE_2D, _colorBuffer );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, winSize.x, winSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		glFramebufferTexture2D( GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _colorBuffer, 0 );

		glBindTexture( GL_TEXTURE_2D, 0 );

		glGenRenderbuffers( 1, &_depthStencilBuffer );
		glBindRenderbuffer( GL_RENDERBUFFER, _depthStencilBuffer );

		glRenderbufferStorage( GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, winSize.x, winSize.y );
		glFramebufferRenderbuffer( GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _depthStencilBuffer );

		glBindRenderbuffer( GL_RENDERBUFFER, 0 );

		int retCode = glCheckFramebufferStatus( GL_FRAMEBUFFER );

		switch (retCode)
		{
			case GL_FRAMEBUFFER_UNDEFINED:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
				break;
			case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
				break;
			case GL_FRAMEBUFFER_UNSUPPORTED:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
				break;
			case GL_TEXTURE_FIXED_SAMPLE_LOCATIONS:
				break;
			case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
				break;
			case GL_FRAMEBUFFER_COMPLETE:
				break;
			default:
				break;
		}

		if ( retCode == GL_FRAMEBUFFER_COMPLETE )
		{
			result = true;

			glEnable(GL_DEPTH_TEST);

			glEnable( GL_STENCIL_TEST );
			glStencilMask( 0x00 );
			glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glBindFramebuffer( GL_FRAMEBUFFER, 0 );

			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );
			_arrayBuffer.genBuffer( VertexArrayObject::BufferType::ELEMENT );

			setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::NO_MVP_POS_UV_TEXTURE ) );

			PosUVVertex vertices[] = { { Vec3(-1.0f, 1.0f, 0.0f ), Vec2( 0.0f, 1.0f ) },
									   { Vec3( -1.0f, -1.0f, 0.0f ), Vec2( 0.0f, 0.0f ) },
									   { Vec3( 1.0f, 1.0f, 0.0f ), Vec2( 1.0f, 1.0f ) },
								   	   { Vec3( 1.0f, -1.0f, 0.0f ), Vec2( 1.0f, 0.0f ) }
			};
			
			_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosUVVertex), sizeof(vertices)/sizeof(PosUVVertex) );

			GLuint indices[] = { 0, 1, 2,
								 1, 2, 3 };

			_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::ELEMENT, indices, sizeof(unsigned int), sizeof(indices)/sizeof(GLuint) );

			_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)0 );
			_arrayBuffer.setupAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)(3*sizeof(GLfloat)) );

		}
		else
		{
			Console::log( "frame buffer init failed" );
			OpenGL::getInstance()->processGLErrors();
			result = true;
		}

		
		glBindFramebuffer( GL_FRAMEBUFFER, 0 );

		return result;
	}
	void CustomFrameBuffer::draw( const Mat4& trnasform )
	{
		auto shader = getShaderProgram();
		if ( shader )
			shader->useProgram();

		glBindTexture( GL_TEXTURE_2D, _colorBuffer );

		_arrayBuffer.drawElements( GL_TRIANGLES, GL_UNSIGNED_INT, 0 );
	}
	void CustomFrameBuffer::bind()
	{
		glBindFramebuffer( GL_FRAMEBUFFER, _fbo );
	}
	void CustomFrameBuffer::unbind()
	{
		glBindFramebuffer( GL_FRAMEBUFFER, 0 );
	}
	void CustomFrameBuffer::onBeforeStartDraw()
	{
		glStencilMask( 0xFF );
		glClearColor( 0.6f, 0.8f, 0.8f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );	
		glStencilMask( 0x00 );
	}
	void CustomFrameBuffer::onDrawFinish()
	{
	}
}