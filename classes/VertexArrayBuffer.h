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


	public:

		VertexArrayBuffer();
		virtual ~VertexArrayBuffer();

		void setupVBOData( const void* data, size_t dataSize );
		void setupEBOdata( const void* data, size_t dataSize );

		void setupAttribPointer( GLuint indx, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer );

		void drawArrays( GLenum mode, GLint first, GLsizei count, ShaderProgram* shader, Texture2D* texture );
		void drawArrays( GLenum mode, GLint first, GLsizei count, ShaderProgram* shader, const std::vector<Texture2D*>& textures );

		void drawElements( GLenum mode, GLsizei count, GLenum type, const void* indices, ShaderProgram* shader, Texture2D* texture );
		void drawElements( GLenum mode, GLsizei count, GLenum type, const void* indices, ShaderProgram* shader, const std::vector<Texture2D*>& textures );


	};

}


#endif