#include <iostream>


#include "FileUtils.h"
#include "ResourcesManager.h"

#include "Rectangle.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"

_USEVE


GLFWwindow* _window = nullptr;
const GLuint WIDTH = 800, HEIGHT = 600;

//void 
void initGL();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// The MAIN function, from here we start the application and run the game loop
int main()
{
	RESOURCES->parceResConfig( "resdb/resources.json" );

	initGL();

    // Uncommenting this call will result in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	std::vector<Primitive*> primitives;

	auto newRect = Rectangle::create();
	newRect->setSize(Size(1.0f, 1.0f));
	newRect->setPosition(Vec(-0.5f, -0.5f));
	newRect->setColor(RGBA::WHITE);
	primitives.push_back(newRect);

	auto newLine = Line::create();
	newLine->setColor(RGBA::RED);
	newLine->setPosition(Vec(-0.8f, -0.8f));
	newLine->setEndPoint(Vec(0.5f, 0.1f));
	primitives.push_back(newLine);

	auto newPoint = Point::create();
	newPoint->setColor(RGBA::BLACK);
	primitives.push_back(newPoint);

	auto newTriangle = Triangle::create();
	newTriangle->setPoints(Vec(0.0f, 0.9f), Vec(-0.9f, -0.9f));
	newTriangle->setColor(RGBA::GREEN);
	primitives.push_back(newTriangle);

    // Game loop
    while (true)
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		for( auto primitive : primitives )
		{
			primitive->draw();
		}

        glfwSwapBuffers(_window);
    }


    glfwTerminate();
    return 0;
}

void initGL()
{
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    _window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(_window);

    // Set the required callback functions
    glfwSetKeyCallback(_window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(_window, &width, &height);  
    glViewport(0, 0, width, height);
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}