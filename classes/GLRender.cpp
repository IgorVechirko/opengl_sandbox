#include "GLRender.h"

#include "Node.h"

_USEVE

GLRender::GLRender()
	: _window( nullptr )
	, _windowWidth( 1024 )
	, _windowHeight( 1024 )
{
}
GLRender::~GLRender()
{
}
GLRender* GLRender::getInstance()
{
	static GLRender instance;
	return &instance;
}
void GLRender::keysCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
void GLRender::init()
{
	if ( !_window )
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
		_window = glfwCreateWindow(_windowWidth, _windowHeight, "LearnOpenGL", nullptr, nullptr);
		glfwMakeContextCurrent(_window);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		glewInit();

		// Define the viewport dimensions
		int width, height;
		glfwGetFramebufferSize(_window, &width, &height);  
		glViewport(0, 0, width, height);
	}
}
void GLRender::addNodeForDraw( Node* node )
{
	auto findIt = std::find(_nodes.begin(), _nodes.end(), node );
	if ( findIt == _nodes.end() )
	{
		node->retain();
		_nodes.push_back( node );
	}
}
void GLRender::delNodeFromDraw( Node* node )
{
	auto findIt = std::find(_nodes.begin(), _nodes.end(), node );
	if ( findIt != _nodes.end() )
	{
		node->release();
		_nodes.erase( findIt );
	}
}
GLuint GLRender::getWindowWidth()
{
	return _windowWidth;
}
GLuint GLRender::getWindowHeight()
{
	return _windowHeight;
}
void GLRender::draw()
{
	glfwPollEvents();

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for ( auto node : _nodes )
	{
		node->draw();
	}

	glfwSwapBuffers(_window);

}