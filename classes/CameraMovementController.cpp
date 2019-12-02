#include "CameraMovementController.h"


_USEVE


CameraMovementController::CameraMovementController()
	: _cameraMoveSpeed( 500.0f )
	, _cameraRotateSensitivity( 0.1f )
	, _mousePos( 0.0f, 0.0f )
	, _mousePosInited( false )
	, _fovAngle( 45.0f )
{
}
CameraMovementController::~CameraMovementController()
{
	if( INPUT->getInputCondtrollerListener() == this )
	{
		INPUT->setInputCondtrollerListener( nullptr );
	}

	SCHEDULER->delUpdateFunc( this );
}
void CameraMovementController::updaeTime( float deltaTme )
{
	float shift = deltaTme * _cameraMoveSpeed;

	if ( _xDirection != eAxisDirection::NONE )
	{
		if ( _xDirection == eAxisDirection::POSITIV )
		{
			CAMERA->moveRight( shift );
		}
		else
		{
			CAMERA->moveLeft( shift );
		}
	}

	if ( _zDirection != eAxisDirection::NONE )
	{
		if ( _zDirection == eAxisDirection::POSITIV )
		{
			CAMERA->moveAhead( shift );
		}
		else
		{
			CAMERA->moveBack( shift );
		}
	}

	if ( _yDirection != eAxisDirection::NONE )
	{
		if ( _yDirection == eAxisDirection::POSITIV )
		{
			CAMERA->moveUp( shift );
		}
		else
		{
			CAMERA->moveDown( shift );
		}
	}
}
void CameraMovementController::onKeyPressed( int aKeyCode )
{
	if ( aKeyCode == GLFW_KEY_W )
	{
		if( _zDirection == eAxisDirection::NONE )
		{
			_zDirection	= eAxisDirection::POSITIV;
		}
	}
	else if ( aKeyCode == GLFW_KEY_S )
	{
		if( _zDirection == eAxisDirection::NONE )
		{
			_zDirection	= eAxisDirection::NEGATIVE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_D )
	{
		if( _xDirection == eAxisDirection::NONE )
		{
			_xDirection	= eAxisDirection::POSITIV;
		}
	}
	else if ( aKeyCode == GLFW_KEY_A )
	{
		if( _xDirection == eAxisDirection::NONE )
		{
			_xDirection	= eAxisDirection::NEGATIVE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_R )
	{
		if( _yDirection == eAxisDirection::NONE )
		{
			_yDirection	= eAxisDirection::POSITIV;
		}
	}
	else if ( aKeyCode == GLFW_KEY_F )
	{
		if( _yDirection == eAxisDirection::NONE )
		{
			_yDirection	= eAxisDirection::NEGATIVE;
		}
	}
}
void CameraMovementController::onKeyPressRepeate( int aKeyCode )
{
	onKeyPressed( aKeyCode );
}
void CameraMovementController::onKeyReleased( int aKeyCode )
{
	if ( aKeyCode == GLFW_KEY_W )
	{
		if ( _zDirection == eAxisDirection::POSITIV )
		{
			_zDirection = eAxisDirection::NONE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_S )
	{
		if ( _zDirection == eAxisDirection::NEGATIVE )
		{
			_zDirection = eAxisDirection::NONE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_D )
	{
		if ( _xDirection == eAxisDirection::POSITIV )
		{
			_xDirection = eAxisDirection::NONE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_A )
	{
		if ( _xDirection == eAxisDirection::NEGATIVE )
		{
			_xDirection = eAxisDirection::NONE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_R )
	{
		if ( _yDirection == eAxisDirection::POSITIV )
		{
			_yDirection = eAxisDirection::NONE;
		}
	}
	else if ( aKeyCode == GLFW_KEY_F )
	{
		if ( _yDirection == eAxisDirection::NEGATIVE )
		{
			_yDirection = eAxisDirection::NONE;
		}
	}
}
void CameraMovementController::onMouseMoved( double posX, double posY )
{
	if ( !_mousePosInited )
	{
		_mousePosInited = true;

		_mousePos.x = posX;
		_mousePos.y = posY;
	}
	
	Vec newMousePos( posX, posY );
	Vec moveDelta = _mousePos - newMousePos;
	moveDelta *= _cameraRotateSensitivity;

	CAMERA->spinPitch( moveDelta.y );
	CAMERA->spinYaw( moveDelta.x );

	_mousePos = newMousePos;
}
void CameraMovementController::onWheelScrolled( float xoffset, float yoffset )
{
	_fovAngle += yoffset;

	auto wndSize = VIEW->getWindowSize();
	CAMERA->setProjection( glm::perspective( glm::radians(_fovAngle), wndSize.x/wndSize.y, 0.1f, 10000.0f ) );
}
void CameraMovementController::init()
{
	auto wndSize = VIEW->getWindowSize();
	Mat4 projection = glm::perspective( glm::radians(_fovAngle), wndSize.x/wndSize.y, 0.1f, 10000.0f );
	CAMERA->setProjection( projection );

	CAMERA->setCameraPos( Vec3( 0.0f, 0.0f, 927.0f ) );

	SCHEDULER->addUpdateFunc( std::bind( &CameraMovementController::updaeTime, this, std::placeholders::_1 ), this );

	INPUT->setInputCondtrollerListener( this );
}