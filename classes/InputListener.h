#ifndef InputListener_H
#define InputListener_H


#include "VECommon.h"

_VESTART


class InputListener
{

	public:

		virtual void onKeyPressed( int keyCode ){};
		virtual void onKeyPressRepeate( int keyCode ){};
		virtual void onKeyReleased( int keyCode ){};
		virtual void onWheelScrolled( float xoffset, float yoffset ){};

		virtual void onMouseMoved( double posX, double posY ){};

};



_VEEND


#endif