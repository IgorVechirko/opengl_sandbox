#ifndef GLContext_H
#define GLContext_H

#include "VECommon.h"

_VESTART

class InputListener;
class GLContext
{

	GLFWwindow* _window;
	GLuint _windowWidth;
	GLuint _windowHeight;

	InputListener* _inputListener;


	void onKeyPressed( int keyCode, int scancode, int action, int modifiers );
	void onMouseMoved( double posX, double posY );
	void onWheelScrolled( double xoffset, double yoffset );


public:

	GLContext();
	GLContext( const GLContext& ) = delete;
	GLContext( GLContext&& ) = delete;
	GLContext& operator= (const GLContext& ) = delete;
	virtual ~GLContext();

	bool initWithWndSize( GLuint wndWidth, GLuint wndHeight );

	GLFWwindow* getWindow();
	Size getWindowSize();

	void setInputListener( InputListener* lst );
	InputListener* getInputListener();

	void setWindowSouldClose();

	void makeCurrent();


	friend void keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers );
	friend void mouseMoved( GLFWwindow* window, double posX, double posY );
	friend void wheelScrolled( GLFWwindow* window, double xoffset, double yoffset );

};


_VEEND


#endif