#ifndef OpenGL_H
#define OpenGL_H

#include "Common.h"

namespace GLSandbox
{

	class GLContext;
	class OpenGL
	{

		OpenGL();
		virtual ~OpenGL();
		MAKE_UNCOPYABLE(OpenGL);

	public:

		static OpenGL* getInstance();

		GLFWwindow* createWindow( GLuint wndWidth, GLuint wndHeight );
		void destroyWindow( GLFWwindow* window );

		void processLasGlfwtError( const std::string& desc );
		void processGlewError( const std::string& desc, GLenum errorCode );

		void poolEvents();


	};


}


#endif