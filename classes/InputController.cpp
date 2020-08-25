#include "InputController.h"

#include "GLView.h"

_USEVE

bool InputController::_callbacksSetuped = false;
std::vector<InputController*> InputController::_controllers;

void InputController::keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	for( auto controller : _controllers )
		controller->onKeyPressed( window, keyCode, scancode, action, modifiers );
}

void InputController::mouseMoved( GLFWwindow* window, double posX, double posY )
{	
	for( auto controller : _controllers )
		controller->onMouseMoved( window, posX, posY );
}

void InputController::wheelScrolled( GLFWwindow* window, double xoffset, double yoffset )
{
	for( auto controller : _controllers )
		controller->onWheelScrolled( window, xoffset, yoffset );
}

InputController::InputController( WorkingScope* scope )
	: WorkingScopeProvider( scope )
	, _inputControllerListener( nullptr )
{
}
InputController::~InputController()
{
	auto findIt = std::find( _controllers.begin(), _controllers.end(), this );
	if ( findIt != _controllers.end() )
	{
		_controllers.erase( findIt );
	}
}

void InputController::init()
{
	if ( !_callbacksSetuped )
	{
		glfwSetKeyCallback( getGLView()->getWindow(), &InputController::keyPressed );

		glfwSetCursorPosCallback( getGLView()->getWindow(), &InputController::mouseMoved );

		glfwSetScrollCallback( getGLView()->getWindow(), &InputController::wheelScrolled );

		_callbacksSetuped = true;
	}

	_controllers.push_back( this );

	glfwSetInputMode( getGLView()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED );

	bool stop = true;
}
void InputController::onKeyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers )
{
	if ( _inputControllerListener && getGLView()->getWindow() == window )
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
	if ( _inputControllerListener && getGLView()->getWindow() == window )
	{
		_inputControllerListener->onMouseMoved( posX, posY );
	}
}
void InputController::onWheelScrolled( GLFWwindow* window, double xoffset, double yoffset )
{
	if( _inputControllerListener && getGLView()->getWindow() == window )
	{
		_inputControllerListener->onWheelScrolled( xoffset, yoffset );
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