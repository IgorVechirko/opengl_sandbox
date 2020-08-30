#include "VertexArrayBuffer.h"



#include "ShaderProgram.h"
#include "Texture2D.h"


namespace GLSandbox
{
	VertexArrayBuffer::VertexArrayBuffer()
		: _vao( NULL )
		, _vbo( NULL )
		, _ebo( NULL )
	{
		glGenVertexArrays( 1, &_vao );
	}
	VertexArrayBuffer::~VertexArrayBuffer()
	{
		glBindVertexArray( _vao );
		glDeleteBuffers( 1, &_vbo );
		glDeleteBuffers( 1, &_ebo );
		glDeleteVertexArrays( 1, &_vao );
	}
	void VertexArrayBuffer::setupVBOData( const void* data, size_t dataSize )
	{
		glBindVertexArray( _vao );

		if( _vbo )
		{
			glBindBuffer( GL_ARRAY_BUFFER, _vbo );
			glBufferSubData( GL_ARRAY_BUFFER, 0, dataSize, data );
		}
		else
		{
			glGenBuffers( 1, &_vbo );
			glBindBuffer( GL_ARRAY_BUFFER, _vbo );
			glBufferData( GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW );
		}

		glBindVertexArray( 0 );

	}
	void VertexArrayBuffer::setupEBOdata( const void* data, size_t dataSize )
	{
		glBindVertexArray( _vao );

		if( _ebo )
		{
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );
			glBufferSubData( GL_ELEMENT_ARRAY_BUFFER, 0, dataSize, data );
		}
		else
		{
			glGenBuffers( 1, &_ebo );
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );
			glBufferData( GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW );
		}

		glBindVertexArray( 0 );
	}
	void VertexArrayBuffer::setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer )
	{
		glBindVertexArray( _vao );
		glVertexAttribPointer( indx, size, type, normalized, stride, pointer );
		glEnableVertexAttribArray(indx);
		glBindVertexArray( 0 );
	}
	void VertexArrayBuffer::drawArrays( GLenum mode, GLint first, GLsizei count, ShaderProgram* shader, Texture2D* texture )
	{
		drawArrays( mode, first, count, shader, std::vector<Texture2D*>{texture} );
	}
	void VertexArrayBuffer::drawArrays( GLenum mode, GLint first, GLsizei count, ShaderProgram* shader, const std::vector<Texture2D*>& textures )
	{
		if ( shader )
			shader->useProgram();

		int textureNum = 0;
		for( auto texture : textures )
		{
			glActiveTexture( GL_TEXTURE0 + textureNum );
			glBindTexture( GL_TEXTURE_2D, texture->getTextureID() );
			textureNum++;
		}

		glBindVertexArray( _vao );
		glDrawArrays( mode, first, count );
		glBindVertexArray( 0 );
	}
	void VertexArrayBuffer::drawElements( GLenum mode, GLsizei count, GLenum type, const void* indices, ShaderProgram* shader, Texture2D* texture )
	{
		drawElements( mode, count, type, indices, shader, std::vector<Texture2D*>{texture} );
	}
	void VertexArrayBuffer::drawElements( GLenum mode, GLsizei count, GLenum type, const void* indices, ShaderProgram* shader, const std::vector<Texture2D*>& textures )
	{
		if ( shader );
			shader->useProgram();

		int textureNum = 0;
		for( auto texture : textures )
		{
			glActiveTexture( GL_TEXTURE0 + textureNum );
			glBindTexture( GL_TEXTURE_2D, texture->getTextureID() );
			textureNum++;
		}

		glBindVertexArray( _vao );
		glDrawElements( mode, count, type, indices );
		glBindVertexArray( 0 );
	}

}