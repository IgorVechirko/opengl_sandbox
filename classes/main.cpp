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

_USEVE


GLFWwindow* _window = nullptr;
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
	RESOURCES->parceResConfig( "resdb/resources.json" );

	GLRender::getInstance()->init();

	auto myNode = Node::create();

	GLRender::getInstance()->addNodeForDraw( myNode );

    // Game loop
    while (true)
    {
		AutoReleasePool::getInstance()->checkAutorelease();

        GLRender::getInstance()->draw();
    }


    glfwTerminate();
    return 0;
}
