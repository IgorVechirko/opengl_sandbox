#include "GLContext.h"

#include "OpenGL.h"
#include "InputListener.h"
#include "Scene.h"

namespace GLSandbox
{

	void GLSandbox::keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
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
	void GLSandbox::mouseMoved( GLFWwindow* window, double posX, double posY )
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
	void GLSandbox::wheelScrolled( GLFWwindow* window, double xoffset, double yoffset )
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
		, _render( nullptr )
		, _scene( nullptr )
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

			_render.setScope( getScope() );
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
	void GLContext::makeCurrent()
	{
		glfwMakeContextCurrent(_window);
	}
	bool GLContext::windowShouldClose()
	{
		return glfwWindowShouldClose(_window );
	}
	void GLContext::setInputListener( InputListener* lst )
	{
		_inputListener = lst;
	}
	InputListener* GLContext::getInputListener()
	{
		return _inputListener;
	}
	void GLContext::setWindowShouldClose()
	{
		glfwSetWindowShouldClose( _window, 1 );
	}
	void GLContext::poolEvents()
	{
		OpenGL::getInstance()->poolEvents();
	}
	GLRender* GLContext::getRender()
	{
		return &_render;
	}
	void GLContext::setScene( Scene* scene )
	{
		if( scene )
		{
			if ( _scene != scene )
			{
				if ( _scene )
					_scene->release();

				scene->retain();
				_scene = scene;
			}
		}
	}
	Scene* GLContext::getScene()
	{
		_ASSERT( _scene != nullptr );
		return _scene;
	}
	void GLContext::drawScene()
	{
		_ASSERT(_scene);
		_render.drawScene( _scene );
	}

}