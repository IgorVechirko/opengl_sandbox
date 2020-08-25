#ifndef GLView_H
#define GLView_H

#include "WorkingScopeProvider.h"

_VESTART

class GLView : public WorkingScopeProvider
{
	GLFWwindow* _window;
	GLuint _windowWidth;
	GLuint _windowHeight;

public:

	GLView( WorkingScope* scope );
	virtual ~GLView();

	void setupWindowSize( GLuint width, GLuint height );
	Size getWindowSize();

	GLFWwindow* getWindow();

};


_VEEND

#endif