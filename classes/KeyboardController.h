#ifndef KeyboardController_H
#define KeyboardController_H

#include "VECommon.h"


_VESTART

class KeyboardControllerListener
{


	public:

		virtual void onKeyPressed( int aKeyCode ){};
		virtual void onKeyPressRepeate( int aKeyCode ){};
		virtual void onKeyReleased( int aKeyCode ){};

};


class KeyboardController
{

	KeyboardControllerListener* _keyboardControllerListener;

public:

	KeyboardController();
	virtual ~KeyboardController();

	void init();

	void onKeyPressed( GLFWwindow* window, int keyCode, int scancode, int action, int modifiers );

	void setKeyboardCondtrollerListener( KeyboardControllerListener* lst );
	KeyboardControllerListener* getKeyboardCondtrollerListener();

};

_VEEND


#endif