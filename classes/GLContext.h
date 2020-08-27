#ifndef GLContext_H
#define GLContext_H

#include "VECommon.h"

_VESTART

class GLContext
{

	GLFWwindow* _window;
	GLuint _windowWidth;
	GLuint _windowHeight;


public:

	GLContext();
	GLContext( const GLContext& ) = delete;
	GLContext( GLContext&& ) = delete;
	GLContext& operator= (const GLContext& ) = delete;
	virtual ~GLContext();

	bool initWithWndSize( GLuint wndWidth, GLuint wndHeight );

	GLFWwindow* getWindow();
	Size getWndSize();

	void makeCurrent();

};


_VEEND


#endif