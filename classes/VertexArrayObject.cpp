#include "VertexArrayObject.h"



#include "ShaderProgram.h"
#include "Texture2D.h"
#include "OpenGL.h"


namespace GLSandbox
{
	VertexArrayObject::VertexArrayObject()
		: _vao( NULL )
		, _vbo( NULL )
		, _ebo( NULL )
		, _vboDataSize( 0 )
		, _eboDataSize( 0 )
		, _indicesAmount( 0 )
		, _verticesAmount( 0 )
	{
		glGenVertexArrays( 1, &_vao );
	}
	VertexArrayObject::~VertexArrayObject()
	{
		glBindVertexArray( _vao );
		glDeleteBuffers( 1, &_vbo );
		glDeleteBuffers( 1, &_ebo );
		glDeleteVertexArrays( 1, &_vao );
	}
	GLenum VertexArrayObject::bufferTypeToGLenum( BufferType type )
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
	GLuint* VertexArrayObject::bufferIDByBufferType( BufferType type )
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
	unsigned int* VertexArrayObject::bufferUnitsAmountByBufferType( BufferType type )
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
	size_t* VertexArrayObject::bufferDatSizebyBufferType( BufferType type )
	{
		size_t* result = nullptr;

		switch( type )
		{
		case BufferType::VERTEX:
			result = &_vboDataSize;
			break;
		case BufferType::ELEMENT:
			result = &_eboDataSize;
			break;
		}

		return result;
	}
	void VertexArrayObject::genBuffer( BufferType bufferType )
	{
		glBindVertexArray( _vao );
		glGenBuffers( 1, bufferIDByBufferType( bufferType ) );

		OpenGL::getInstance()->processGLErrors();
	}
	void VertexArrayObject::setupBufferData( BufferType bufferType, const void* data, size_t dataUnitSize, unsigned int dataUnitsAmount )
	{
		auto target = bufferTypeToGLenum( bufferType );
		auto bufferID = bufferIDByBufferType( bufferType );
		auto bufferUnitsAmount = bufferUnitsAmountByBufferType( bufferType );
		auto bufferDataSize = bufferDatSizebyBufferType( bufferType );

		size_t newDataSize = dataUnitSize * dataUnitsAmount;

		_ASSERT( *bufferID );

		glBindVertexArray( _vao );
		glBindBuffer( target, *bufferID );

		if ( (*bufferDataSize) >= newDataSize  )
		{
			glBufferSubData( target, 0, newDataSize, data );
		}
		else
		{
			glBufferData( target, newDataSize, data, GL_STATIC_DRAW );
			*bufferDataSize = newDataSize;
		}

		*bufferUnitsAmount = dataUnitsAmount;
		
		glBindVertexArray( 0 );
		OpenGL::getInstance()->processGLErrors();
	}
	void VertexArrayObject::setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer )
	{
		_ASSERT( _vbo );

		glBindVertexArray( _vao );
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glVertexAttribPointer( indx, size, type, normalized, stride, pointer );
		glEnableVertexAttribArray(indx);
		glBindVertexArray( 0 );

		OpenGL::getInstance()->processGLErrors();
	}
	void VertexArrayObject::drawArrays( GLenum mode, GLint first )
	{
		_ASSERT( _vbo );

		glBindVertexArray( _vao );
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		
		OpenGL::getInstance()->processGLErrors();

		glDrawArrays( mode, first, _verticesAmount );
			
		glBindVertexArray( 0 );
	}
	void VertexArrayObject::drawElements( GLenum mode, GLenum type, const void* indices )
	{
		_ASSERT( _ebo && _vbo );
		
		glBindVertexArray( _vao );
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );

		OpenGL::getInstance()->processGLErrors();

		glDrawElements( mode, _indicesAmount, type, indices );
			
		glBindVertexArray( 0 );
	}

}