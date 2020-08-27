#include "GLContext.h"

#include "OpenGL.h"
#include "InputListener.h"

_USEVE

void VEngine::keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	if ( window )
	{
		auto glContext = reinterpret_cast<GLContext*>(glfwGetWindowUserPointer(window) );

		if( glContext )
		{
			glContext->onKeyPressed( keyCode, scancode, action, modifiers );
		}
	}
}
void VEngine::mouseMoved( GLFWwindow* window, double posX, double posY )
{
	if ( window )
	{
		auto glContext = reinterpret_cast<GLContext*>(glfwGetWindowUserPointer(window) );

		if( glContext )
		{
			glContext->onMouseMoved( posX, posY );
		}
	}
}
void VEngine::wheelScrolled( GLFWwindow* window, double xoffset, double yoffset )
{
	if ( window )
	{
		auto glContext = reinterpret_cast<GLContext*>(glfwGetWindowUserPointer(window) );

		if( glContext )
		{
			glContext->onWheelScrolled( xoffset, yoffset );
		}
	}
}


GLContext::GLContext()
	: _window( nullptr )
	, _windowWidth( 0 )
	, _windowHeight( 0 )
{
}
GLContext::~GLContext()
{
	OpenGL::getInstance()->destroyWindow( _window );
}
void GLContext::onKeyPressed( int keyCode, int scancode, int action, int modifiers )
{
	if ( _inputListener )
	{
		switch (action)
		{
		case GLFW_PRESS:
			_inputListener->onKeyPressed( keyCode );
			break;
		case GLFW_REPEAT:
			_inputListener->onKeyPressRepeate( keyCode );
			break;
		case GLFW_RELEASE:
			_inputListener->onKeyReleased( keyCode );
			break;
		default:
			break;
		}
	}
}
void GLContext::onMouseMoved( double posX, double posY )
{
	if ( _inputListener )
	{
		_inputListener->onMouseMoved( posX, posY );
	}
}
void GLContext::onWheelScrolled( double xoffset, double yoffset )
{
	if ( _inputListener )
	{
		_inputListener->onWheelScrolled( xoffset, yoffset );
	}
}
bool GLContext::initWithWndSize( GLuint wndWidth, GLuint wndHeight )
{
	_windowWidth = wndWidth;
	_windowHeight = wndHeight;

	_window = OpenGL::getInstance()->createWindow( wndWidth, wndHeight );

	if ( _window )
	{
		makeCurrent();

		glfwSetWindowUserPointer( _window, this );

		glfwSetKeyCallback( _window, keyPressed );
		glfwSetCursorPosCallback( _window, mouseMoved );
		glfwSetScrollCallback( _window, wheelScrolled );

		glfwSetInputMode( _window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
	}
	else
	{
		return false;
	}

	return true;
}
GLFWwindow* GLContext::getWindow()
{
	return _window;
}
Size GLContext::getWindowSize()
{
	return Size( _windowWidth, _windowHeight );
}
void GLContext::setInputListener( InputListener* lst )
{
	_inputListener = lst;
}
InputListener* GLContext::getInputListener()
{
	return _inputListener;
}
void GLContext::setWindowSouldClose()
{
	glfwSetWindowShouldClose( _window, 1 );
}
void GLContext::makeCurrent()
{
	glfwMakeContextCurrent(_window);
}