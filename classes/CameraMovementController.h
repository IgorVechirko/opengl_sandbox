#ifndef CameraMovementController_H
#define CameraMovementController_H

#include "Director.h"

_VESTART

class Camera;
class CameraMovementController : public InputControllerListener
{
	enum class eAxisDirection
	{
		NONE,
		POSITIV,
		NEGATIVE
	};

	eAxisDirection _xDirection;
	eAxisDirection _yDirection;
	eAxisDirection _zDirection;

	float _fovAngle;

	float _cameraMoveSpeed;

	float _cameraRotateSensitivity;

	bool _mousePosInited;
	Vec _mousePos;


	void updaeTime( float deltaTme );

protected:


	virtual void onKeyPressed( int aKeyCode ) override;
	virtual void onKeyPressRepeate( int aKeyCode ) override;
	virtual void onKeyReleased( int aKeyCode ) override;

	virtual void onMouseMoved( double posX, double posY ) override;

	virtual void onWheelScrolled( float xoffset, float yoffset ) override;

	virtual Camera* getCamera(){ return nullptr; };


public:

	CameraMovementController();
	virtual ~CameraMovementController();

	void init();
};


_VEEND


#endif