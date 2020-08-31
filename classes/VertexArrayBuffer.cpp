#include "VertexArrayBuffer.h"



#include "ShaderProgram.h"
#include "Texture2D.h"
#include "OpenGL.h"


namespace GLSandbox
{
	VertexArrayBuffer::VertexArrayBuffer()
		: _vao( NULL )
		, _vbo( NULL )
		, _ebo( NULL )
		, _indicesAmount( 0 )
		, _verticesAmount( 0 )
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
	GLenum VertexArrayBuffer::bufferTypeToGLenum( BufferType type )
	{
		GLenum result = NULL;

		switch( type )
		{
		case BufferType::VERTEX:
			result = GL_ARRAY_BUFFER;
			break;
		case BufferType::ELEMENT:
			result = GL_ELEMENT_ARRAY_BUFFER;
			break;
		}

		return result;
	}
	GLuint* VertexArrayBuffer::bufferIDByBufferType( BufferType type )
	{
		GLuint* result = nullptr;

		switch( type )
		{
		case BufferType::VERTEX:
			result = &_vbo;
			break;
		case BufferType::ELEMENT:
			result = &_ebo;
			break;
		}

		return result;
	}
	unsigned int* VertexArrayBuffer::bufferUnitsAmountByBufferType( BufferType type )
	{
		unsigned int* result = nullptr;

		switch( type )
		{
		case BufferType::VERTEX:
			result = &_verticesAmount;
			break;
		case BufferType::ELEMENT:
			result = &_indicesAmount;
			break;
		}

		return result;
	}
	void VertexArrayBuffer::setupBufferData( BufferType type, const void* data, size_t dataUnitSize, unsigned int dataUnitsAmount )
	{
		auto target = bufferTypeToGLenum( type );
		auto bufferID = bufferIDByBufferType( type );
		auto bufferUnitsAmount = bufferUnitsAmountByBufferType( type );

		glBindVertexArray( _vao );

		if( *bufferID )
		{
			glBindBuffer( target, *bufferID );
			glBufferSubData( target, 0, dataUnitSize*dataUnitsAmount, data );
		}
		else
		{
			glGenBuffers( 1, bufferID );
			glBindBuffer( target, *bufferID );
			glBufferData( target, dataUnitSize*dataUnitsAmount, data, GL_STATIC_DRAW );
		}

		*bufferUnitsAmount = dataUnitsAmount;

		
		glBindVertexArray( 0 );
	}
	void VertexArrayBuffer::setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer )
	{
		glBindVertexArray( _vao );
		glVertexAttribPointer( indx, size, type, normalized, stride, pointer );
		glEnableVertexAttribArray(indx);
		glBindVertexArray( 0 );
	}
	void VertexArrayBuffer::drawArrays( GLenum mode, GLint first )
	{
		if( _vbo )
		{
			glBindVertexArray( _vao );
			glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		
			OpenGL::getInstance()->processGLErrors();

			glDrawArrays( mode, first, _verticesAmount );
			
			glBindVertexArray( 0 );
		}
	}
	void VertexArrayBuffer::drawElements( GLenum mode, GLenum type, const void* indices )
	{
		if( _ebo && _vbo )
		{
			glBindVertexArray( _vao );
			glBindBuffer( GL_ARRAY_BUFFER, _vbo );
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );

			OpenGL::getInstance()->processGLErrors();

			glDrawElements( mode, _indicesAmount, type, indices );
			
			glBindVertexArray( 0 );
		}
	}

}