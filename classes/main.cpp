#include <iostream>


#include "FileUtils.h"
#include "ResourcesManager.h"

#include "Rectangle.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"
#include "GLRender.h"
#include "Node.h"
#include "AutoRelesaePool.h"
#include "Sprite.h"
#include "Camera.h"

_USEVE


GLFWwindow* _window = nullptr;
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
	RESOURCES->parceResConfig( "resdb/resources.json" );

	GLRender::getInstance()->init();

	auto customCamera = Camera::create();

	Size wndSize( GLRender::getInstance()->getWindowWidth(), GLRender::getInstance()->getWindowHeight() );
	Mat4 projection = glm::ortho( -1.0f * wndSize.x/2.0f, wndSize.x/2.0f, -1.0f * wndSize.y/2.0f, wndSize.y/2.0f, 0.1f, 100.0f );
	customCamera->setProjection(projection);
	GLRender::getInstance()->setCamera( customCamera );

	auto mySprite = Sprite::create( RES_PATH("MOUNTAIN") );

	mySprite->setPosition( Vec3( 0.0f, 0.0f, -0.1f ) );

	GLRender::getInstance()->addNodeForDraw( mySprite );

    // Game loop
    while (true)
    {
		AutoReleasePool::getInstance()->checkAutorelease();

        GLRender::getInstance()->draw();
    }


    glfwTerminate();
    return 0;
}
