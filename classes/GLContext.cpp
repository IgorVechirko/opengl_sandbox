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
		if ( _scene )
		{
			_scene->release();
			_scene = nullptr;
		}

		OpenGL::getInstance()->destroyWindow( _window );
	}
	void GLContext::onKeyPressed( int keyCode, int scancode, int action, int modifiers )
	{
		switch (action)
		{
		case GLFW_PRESS:
			for( auto listener : _inputListeners )
				listener->onKeyPressed( keyCode );
			break;
		case GLFW_REPEAT:
			for( auto listener : _inputListeners )
				listener->onKeyPressRepeate( keyCode );
			break;
		case GLFW_RELEASE:
			for( auto listener : _inputListeners )
				listener->onKeyReleased( keyCode );
			break;
		default:
			break;
		}
	}
	void GLContext::onMouseMoved( double posX, double posY )
	{
		for( auto listener : _inputListeners )
			listener->onMouseMoved( posX, posY );
	}
	void GLContext::onWheelScrolled( double xoffset, double yoffset )
	{
		for( auto listener : _inputListeners )
			listener->onWheelScrolled( static_cast<float>(xoffset), static_cast<float>(yoffset) );
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
	Size GLContext::getWindowSize() const
	{
		return Size( _windowWidth, _windowHeight );
	}
	void GLContext::makeCurrent()
	{
		glfwMakeContextCurrent(_window);
	}
	void GLContext::setWindowShouldClose()
	{
		glfwSetWindowUserPointer( _window, nullptr );

		glfwSetKeyCallback( _window, nullptr );
		glfwSetCursorPosCallback( _window, nullptr );
		glfwSetScrollCallback( _window, nullptr );

		glfwSetWindowShouldClose( _window, 1 );
	}
	bool GLContext::windowShouldClose()
	{
		return glfwWindowShouldClose(_window );
	}
	void GLContext::swapBuffers()
	{
		glfwSwapBuffers( _window );
	}
	void GLContext::addInputListener( InputListener* lst )
	{
		if ( lst )
		{
			auto findIt = std::find( _inputListeners.begin(), _inputListeners.end(), lst );
			if ( findIt == _inputListeners.end() )
			{
				_inputListeners.push_back( lst );
			}
		}
	}
	void GLContext::delInputListener( InputListener* lst )
	{
		if ( lst )
		{
			auto findIt = std::find( _inputListeners.begin(), _inputListeners.end(), lst );
			if ( findIt != _inputListeners.end() )
			{
				_inputListeners.erase( findIt );
			}
		}
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