#include "CameraMovementController.h"


_USEVE


CameraMovementController::CameraMovementController()
	: _cameraPos( 0.0f, 0.0f, 1.0f )
	, _cameraFront( 0.0f, 0.0f, -1.0f )
	, _cameraUp( 0.0f, 1.0f, 0.0f )
	, _xDirection( eAxisDirection::NONE )
	, _yDirection( eAxisDirection::NONE )
	, _zDirection( eAxisDirection::NONE )
	, _cameraMoveSpeed( 10.0f )
	, _cameraRotateSensitivity( 0.1f )
	, _cameraPitch( 0.0f )
	, _cameraYaw( -90.0f )
	, _cameraRoll( 0.0f )
	, _anglesDirty( false )
	, _mousePos( 0.0f, 0.0f )
	, _mousePosInited( false )
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
float CameraMovementController::getAbsoluteXPos( double posX )
{
	return VIEW->getWindowSize().x * posX;

}
float CameraMovementController::getAbsoluteYPos( double posY )
{
	return VIEW->getWindowSize().y * posY;
}
void CameraMovementController::updaeTime( float deltaTme )
{
	bool recalcLookAt = false;

	if ( _xDirection != eAxisDirection::NONE )
	{
		float multiplier = _xDirection == eAxisDirection::POSITIV ? 1.0f : -1.0f;
		_cameraPos += multiplier * glm::normalize( glm::cross( _cameraFront,_cameraUp ) ) * _cameraMoveSpeed;

		recalcLookAt = true;
	}

	if ( _zDirection != eAxisDirection::NONE )
	{
		float multiplier = _zDirection == eAxisDirection::POSITIV ? 1.0f : -1.0f;
		_cameraPos += multiplier * _cameraFront * _cameraMoveSpeed;

		recalcLookAt = true;
	}

	if ( _yDirection != eAxisDirection::NONE )
	{
		float multiplier = _yDirection == eAxisDirection::POSITIV ? 1.0f : -1.0f;
		_cameraPos += multiplier * _cameraUp * _cameraMoveSpeed;

		recalcLookAt = true;
	}

	if ( _anglesDirty )
	{
		_anglesDirty = false;
		recalcLookAt = true;

		_cameraFront.x = glm::cos( glm::radians(_cameraPitch)) * glm::cos( glm::radians(_cameraYaw) );
		_cameraFront.y = glm::sin( glm::radians(_cameraPitch) );
		_cameraFront.z = glm::cos( glm::radians(_cameraPitch) ) * glm::sin( glm::radians(_cameraYaw) );
	}

	if ( recalcLookAt )
	{
		Mat4 view( 1.0f );
		view = glm::lookAt( _cameraPos, _cameraPos + _cameraFront, _cameraUp );
		CAMERA->setView( view );
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

	if ( moveDelta.y > 0.0f && _cameraPitch < 90.0f )
	{
		_cameraPitch += moveDelta.y;
	}
	else if ( moveDelta.y < 0.0f && _cameraPitch > -90.0f )
	{
		_cameraPitch += moveDelta.y;
	}

	_cameraYaw -= moveDelta.x;

	if ( _cameraYaw > 360.0f )
	{
		_cameraYaw -= 360.0f;
	}
	else if ( _cameraYaw < -360.0f )
	{
		_cameraYaw += 360.0f;
	}

	_mousePos = newMousePos;
	_anglesDirty = true;
}
void CameraMovementController::init()
{
	auto wndSize = VIEW->getWindowSize();
	Mat4 projection = glm::perspective( glm::radians(45.0f), wndSize.x/wndSize.y, 0.1f, 10000.0f );
	CAMERA->setProjection( projection );

	_cameraPos = Vec3( 0.0f, 0.0f, 927.0f );

	Mat4 view(1.0f);
	view = glm::lookAt( _cameraPos, _cameraPos + _cameraFront, _cameraUp );
	
	CAMERA->setView( view );

	SCHEDULER->addUpdateFunc( std::bind( &CameraMovementController::updaeTime, this, std::placeholders::_1 ), this );

	INPUT->setInputCondtrollerListener( this );
}