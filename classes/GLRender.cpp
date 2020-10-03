#include "GLRender.h"

#include "Scene.h"
#include "GLContext.h"
#include "WorkingScope.h"
#include "OpenGL.h"


namespace GLSandbox
{

	GLRender::GLRender( WorkingScope* scope )
		: WorkingScopeProvider( scope )
	{
	}
	GLRender::~GLRender()
	{
	}
	void GLRender::init()
	{
		glEnable(GL_DEPTH_TEST);

		glEnable( GL_STENCIL_TEST );
		glStencilMask( 0x00 );
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	}
	void GLRender::drawScene( Scene* scene )
	{
		glStencilMask( 0xFF );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );	
		glStencilMask( 0x00 );

		OpenGL::getInstance()->processGLErrors();
		scene->drawTraversal( Mat4(1.0f) );

		getGLContext()->swapBuffers();

	}

}