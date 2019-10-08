#ifndef GLView_H
#define GLView_H

#include "VECommon.h"

_VESTART

class GLRender;
class GLView
{
	GLFWwindow* _window;
	GLuint _windowWidth;
	GLuint _windowHeight;

public:

	GLView();
	virtual ~GLView();

	void setupWindowSize( GLuint width, GLuint height );
	Size getWindowSize();

	GLFWwindow* getWindow();

};


_VEEND

#endif