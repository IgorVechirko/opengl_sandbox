#ifndef VertexArrayBuffer_H
#define VertexArrayBuffer_H

#include "Ref.h"
#include "NodeExtensions.h"

namespace GLSandbox
{
	class VertexArrayBuffer
	{

		GLuint _vao;
		GLuint _vbo;
		GLuint _ebo;

		int _indicesAmount;


	public:

		VertexArrayBuffer();
		virtual ~VertexArrayBuffer();

		void setupVBOData( const void* data, size_t dataSize );
		void setupEBOdata( const std::vector<unsigned int>& indices );

		void setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer );

		void drawArrays( GLenum mode, GLint first, GLsizei count );
		void drawElements( GLenum mode, GLenum type, const void* indices );


	};

}


#endif