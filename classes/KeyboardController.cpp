#include "KeyboardController.h"

#include "Director.h"

_USEVE

void keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	KEYS->onKeyPressed( window, keyCode, scancode, action, modifiers );
}

KeyboardController::KeyboardController()
	: _keyboardControllerListener( nullptr )
{
}
KeyboardController::~KeyboardController()
{
}

void KeyboardController::init()
{
	auto ret = glfwSetKeyCallback( VIEW->getWindow(), &keyPressed );
	bool stop = true;
}
void KeyboardController::onKeyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	if ( _keyboardControllerListener )
	{
		switch (action)
		{
		case GLFW_PRESS:
			_keyboardControllerListener->onKeyPressed( keyCode );
			break;
		case GLFW_REPEAT:
			_keyboardControllerListener->onKeyPressRepeate( keyCode );
			break;
		case GLFW_RELEASE:
			_keyboardControllerListener->onKeyReleased( keyCode );
			break;
		default:
			break;
		}
	}
}
void KeyboardController::setKeyboardCondtrollerListener( KeyboardControllerListener* lst )
{
	_keyboardControllerListener = lst;
}
KeyboardControllerListener* KeyboardController::getKeyboardCondtrollerListener()
{
	return _keyboardControllerListener;
}