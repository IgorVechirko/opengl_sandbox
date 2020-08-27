#include "GLContext.h"

_USEVE


GLContext::GLContext()
	: _window( nullptr )
	, _windowWidth( 0 )
	, _windowHeight( 0 )
{
}
GLContext::~GLContext()
{
}
bool GLContext::initWithWndSize( GLuint wndWidth, GLuint wndHeight )
{
	_windowWidth = wndWidth;
	_windowHeight = wndHeight;

	//_window = glfwCreateWindow( _windowWidth, _windowHeight, "openGL sandbox", nullptr, nullptr );

	if ( !_window )
	{
		return false;
	}

	return true;
}
GLFWwindow* GLContext::getWindow()
{
	return _window;
}
Size GLContext::getWndSize()
{
	return Size( _windowWidth, _windowHeight );
}
void GLContext::makeCurrent()
{
	glfwMakeContextCurrent(_window);
}