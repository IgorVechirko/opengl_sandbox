#include "GLRender.h"

#include "Scene.h"
#include "GLContext.h"



_USEVE

GLRender::GLRender( WorkingScope* scope )
	: WorkingScopeProvider( scope )
{
}
GLRender::~GLRender()
{
}
void GLRender::init()
{
}
void GLRender::drawScene( Scene* scene )
{
	glEnable(GL_DEPTH_TEST);
	glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );

	glfwPollEvents();

	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );

	scene->visit( this );

	glfwSwapBuffers( getGLContext()->getWindow() );

}