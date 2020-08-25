#ifndef InputController_H
#define InputController_H

#include "WorkingScopeProvider.h"


_VESTART

class InputControllerListener
{


	public:

		virtual void onKeyPressed( int keyCode ){};
		virtual void onKeyPressRepeate( int keyCode ){};
		virtual void onKeyReleased( int keyCode ){};
		virtual void onWheelScrolled( float xoffset, float yoffset ){};

		virtual void onMouseMoved( double posX, double posY ){};

};


class InputController : public WorkingScopeProvider
{
	static bool _callbacksSetuped;

	static std::vector<InputController*> _controllers;


	InputControllerListener* _inputControllerListener;

public:

	static void keyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers );
	static void mouseMoved( GLFWwindow* window, double posX, double posY );
	static void wheelScrolled( GLFWwindow* window, double xoffset, double yoffset );

	InputController( WorkingScope* scope );
	virtual ~InputController();

	void init();

	void onKeyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers );
	void onMouseMoved( GLFWwindow* window, double posX, double posY );
	void onWheelScrolled( GLFWwindow* window, double xoffset, double yoffset );

	void setInputCondtrollerListener( InputControllerListener* lst );
	InputControllerListener* getInputCondtrollerListener();

};

_VEEND


#endif