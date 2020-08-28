#include "OpenGL.h"

namespace GLSandbox
{

	OpenGL::OpenGL()
	{
		if ( !glfwInit() )
		{
			processLasGlfwtError( "glfwInit error" );

			glfwTerminate();

			exit(1);
		}
	}
	OpenGL::~OpenGL()
	{
		glfwTerminate();
	}
	OpenGL* OpenGL::getInstance()
	{
		static OpenGL instance;
		return &instance;

	}
	GLFWwindow* OpenGL::createWindow( GLuint wndWidth, GLuint wndHeight )
	{
		GLFWwindow* result = nullptr;

		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
		glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );

		result = glfwCreateWindow( wndWidth, wndHeight, "openGL sandbox", nullptr, nullptr );

		if ( !result )
		{
			processLasGlfwtError( "create window error" );
			return nullptr;
		}

		glfwMakeContextCurrent(result);

		glewExperimental = GL_TRUE;
	
		auto glewResult = glewInit();
		if ( glewResult != GLEW_OK )
		{
			processGlewError( "glewInit error", glewResult );

			glfwDestroyWindow( result );
			return nullptr;
		}


		int width;
		int height;
		glfwGetFramebufferSize( result, &width, &height );
		glViewport( 0, 0, width, height );

		glDisable( GL_DEPTH_TEST );

		return result;
	}
	void OpenGL::destroyWindow( GLFWwindow* window )
	{
		glfwDestroyWindow( window );
	}
	void OpenGL::processLasGlfwtError( const std::string& desc )
	{
		const char* errorDesc = nullptr;
		auto errorCode = glfwGetError( &errorDesc );

		if( errorDesc )
		{
			Console::log( desc, ". Code ", errorCode, ": ", errorDesc );
		}
		else
		{
			Console::log( desc, ". Code ", errorCode );
		}
	}
	void OpenGL::processGlewError( const std::string& desc, GLenum errorCode )
	{
		auto errorDesc = glewGetErrorString( errorCode );

		if( errorDesc )
		{
			Console::log( desc, ". Code ", errorCode, ": ", errorDesc );
		}
		else
		{
			Console::log( desc, ". Code ", errorCode );
		}
	}
	void OpenGL::poolEvents()
	{
		glfwPollEvents();
	}

}