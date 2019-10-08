#include <iostream>


#include "VECommon.h"
#include "Application.h"

_USEVE


// The MAIN function, from here we start the application and run the game loop
int main()
{
	/*auto customCamera = Camera::create();

	Size wndSize( GLRender::getInstance()->getWindowWidth(), GLRender::getInstance()->getWindowHeight() );
	Mat4 projection = glm::ortho( -1.0f * wndSize.x/2.0f, wndSize.x/2.0f, -1.0f * wndSize.y/2.0f, wndSize.y/2.0f, -0.1f, 100.0f );
	customCamera->setProjection(projection);*/

	Application::getInstance()->run();


    glfwTerminate();
    return 0;
}
