#include "InputController.h"

#include "Director.h"

_USEVE

void keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	INPUT->onKeyPressed( window, keyCode, scancode, action, modifiers );
}

void mouseMoved( GLFWwindow* window, double posX, double posY )
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	INPUT->onMouseMoved( window, posX, posY );
}

InputController::InputController()
	: _inputControllerListener( nullptr )
{
}
InputController::~InputController()
{
}

void InputController::init()
{
	auto ret = glfwSetKeyCallback( VIEW->getWindow(), &keyPressed );

	glfwSetCursorPosCallback( VIEW->getWindow(), &mouseMoved );

	bool stop = true;
}
void InputController::onKeyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	if ( _inputControllerListener )
	{
		switch (action)
		{
		case GLFW_PRESS:
			_inputControllerListener->onKeyPressed( keyCode );
			break;
		case GLFW_REPEAT:
			_inputControllerListener->onKeyPressRepeate( keyCode );
			break;
		case GLFW_RELEASE:
			_inputControllerListener->onKeyReleased( keyCode );
			break;
		default:
			break;
		}
	}
}
void InputController::onMouseMoved( GLFWwindow* window, double posX, double posY )
{
	if ( _inputControllerListener )
	{
		_inputControllerListener->onMouseMoved( posX, posY );
	}
}
void InputController::setInputCondtrollerListener( InputControllerListener* lst )
{
	_inputControllerListener = lst;
}
InputControllerListener* InputController::getInputCondtrollerListener()
{
	return _inputControllerListener;
}