#include "OpenGL.h"

_USEVE


OpenGL::OpenGL()
{
}
OpenGL::~OpenGL()
{
}
OpenGL* OpenGL::getInstance()
{
	static OpenGL instance;
	return &instance;

}
GLFWwindow* OpenGL::createWindow( GLuint wndWidth, GLuint wndHeight )
{
}