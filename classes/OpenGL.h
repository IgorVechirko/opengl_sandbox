#ifndef OpenGL_H
#define OpenGL_H

#include "VECommon.h"

_VESTART


class GLContext;
class OpenGL
{

	OpenGL();

public:

	virtual ~OpenGL();

	static OpenGL* getInstance();

	GLFWwindow* createWindow( GLuint wndWidth, GLuint wndHeight );


};


_VEEND


#endif