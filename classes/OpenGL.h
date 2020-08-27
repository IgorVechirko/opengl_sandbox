#ifndef OpenGL_H
#define OpenGL_H

#include "VECommon.h"

_VESTART


class GLContext;
class OpenGL
{

	OpenGL();
	OpenGL( const OpenGL& ) = delete;
	OpenGL( OpenGL&& ) = delete;
	const OpenGL& operator= ( const OpenGL& ) = delete;

public:

	virtual ~OpenGL();

	static OpenGL* getInstance();

	GLFWwindow* createWindow( GLuint wndWidth, GLuint wndHeight );
	void destroyWindow( GLFWwindow* window );

	void processLasGlfwtError( const std::string& desc );
	void processGlewError( const std::string& desc, GLenum errorCode );


};


_VEEND


#endif