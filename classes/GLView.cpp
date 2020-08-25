#include "GLView.h"



_USEVE


GLView::GLView( WorkingScope* scope )
	: WorkingScopeProvider( scope )
	, _window( nullptr )
	, _windowWidth( 0 )
	, _windowHeight( 0 )
{
}
GLView::~GLView()
{
}
void GLView::setupWindowSize( GLuint width, GLuint height )
{
	if( !_window )
	{
		_windowWidth = width;
		_windowHeight = height;

		LOG( "Starting GLFW context, OpenGL 3.5" );

		glfwInit();
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
		glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );

		_window = glfwCreateWindow( _windowWidth, _windowHeight, "LearnOpenGL", nullptr, nullptr );
		glfwMakeContextCurrent(_window);

		glewExperimental = GL_TRUE;

		glewInit();

		int width;
		int height;
		glfwGetFramebufferSize( _window, &width, &height );
		glViewport( 0, 0, width, height );

		glDisable( GL_DEPTH_TEST );
	}
}
Size GLView::getWindowSize()
{
	return Size( _windowWidth, _windowHeight );
}
GLFWwindow* GLView::getWindow()
{
	return _window;
}