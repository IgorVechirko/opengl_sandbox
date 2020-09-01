#ifndef VertexArrayBuffer_H
#define VertexArrayBuffer_H

#include "Ref.h"
#include "NodeExtensions.h"

namespace GLSandbox
{
	class VertexArrayBuffer
	{

	public:

		enum class BufferType
		{
			VERTEX,
			ELEMENT
		};


		GLuint _vao;
		GLuint _vbo;
		GLuint _ebo;

		size_t _vboDataSize;
		size_t _eboDataSize;

		unsigned int _indicesAmount;
		unsigned int _verticesAmount;


		GLenum bufferTypeToGLenum( BufferType type );
		GLuint* bufferIDByBufferType( BufferType type );
		unsigned int* bufferUnitsAmountByBufferType( BufferType type );
		size_t* bufferDatSizebyBufferType( BufferType type );

	public:

		VertexArrayBuffer();
		virtual ~VertexArrayBuffer();

		void genBuffer( BufferType bufferType );
		void setupBufferData( BufferType bufferType, const void* data, size_t dataUnitSize, unsigned int dataUnitsAmount );

		void setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer );

		void drawArrays( GLenum mode, GLint first );
		void drawElements( GLenum mode, GLenum type, const void* indices );


	};

}


#endif