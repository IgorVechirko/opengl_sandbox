#ifndef CameraMovementController_H
#define CameraMovementController_H

#include "Director.h"

_VESTART


class CameraMovementController : public InputControllerListener
{
	enum class eAxisDirection
	{
		NONE,
		POSITIV,
		NEGATIVE
	};

	Vec3 _cameraPos;
	Vec3 _cameraFront;
	Vec3 _cameraUp;

	eAxisDirection _xDirection;
	eAxisDirection _yDirection;
	eAxisDirection _zDirection;

	float _cameraMoveSpeed;

	float _cameraRotateSensitivity;

	float _cameraPitch;
	float _cameraYaw;
	float _cameraRoll;
	bool _anglesDirty;

	bool _mousePosInited;
	Vec _mousePos;



	void updaeTime( float deltaTme );

	float getAbsoluteXPos( double posX );
	float getAbsoluteYPos( double posY );


protected:


	virtual void onKeyPressed( int aKeyCode ) override;
	virtual void onKeyPressRepeate( int aKeyCode ) override;
	virtual void onKeyReleased( int aKeyCode ) override;

	virtual void onMouseMoved( double posX, double posY ) override;


public:

	CameraMovementController();
	virtual ~CameraMovementController();

	void init();
};


_VEEND


#endif