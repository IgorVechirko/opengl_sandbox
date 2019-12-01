#include "GLRender.h"

#include "Director.h"

_USEVE

GLRender::GLRender()
	: _lightSource( nullptr )
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

	glfwSwapBuffers( VIEW->getWindow() );

}
void GLRender::setLightSource( LightSource* source )
{
	_lightSource = source;
}
LightSource* GLRender::getLightSource()
{
	return _lightSource;
}