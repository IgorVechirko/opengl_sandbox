#ifndef GLContext_H
#define GLContext_H

#include "GLRender.h"

namespace GLSandbox
{

	class InputListener;
	class Scene;
	class GLContext : public WorkingScopeProvider
	{

		GLFWwindow* _window;
		GLuint _windowWidth;
		GLuint _windowHeight;

		InputListener* _inputListener;

		Scene* _scene;
		GLRender _render;


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

		void makeCurrent();

		void setInputListener( InputListener* lst );
		InputListener* getInputListener();

		void setWindowShouldClose();
		bool windowShouldClose();

		void swapBuffers();

		void poolEvents();

		GLRender* getRender();

		void setScene( Scene* scene );
		Scene* getScene();
		void drawScene();


		friend void keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers );
		friend void mouseMoved( GLFWwindow* window, double posX, double posY );
		friend void wheelScrolled( GLFWwindow* window, double xoffset, double yoffset );

	};


}


#endif