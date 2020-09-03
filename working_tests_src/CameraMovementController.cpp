#include "CameraMovementController.h"

#include "GLContext.h"
#include "TimeScheduler.h"


namespace WorkingTests
{
	CameraMovementController::CameraMovementController()
		: _cameraMoveSpeed( 5.0f )
		, _cameraRotateSensitivity( 0.1f )
		, _mousePos( 0.0f, 0.0f )
		, _mousePosInited( false )
		, _fovAngle( 45.0f )
		, _xDirection( eAxisDirection::NONE )
		, _yDirection( eAxisDirection::NONE )
		, _zDirection( eAxisDirection::NONE )
		, _camera( nullptr )
	{
	}
	CameraMovementController::~CameraMovementController()
	{
		if( getGLContext()->getInputListener() == this )
		{
			getGLContext()->setInputListener( nullptr );
		}

		getTimeScheduler()->delUpdateFunc( this );
	}
	void CameraMovementController::updaeTime( float deltaTme )
	{
		float shift = deltaTme * _cameraMoveSpeed;

		if ( _xDirection != eAxisDirection::NONE )
		{
			if ( _xDirection == eAxisDirection::POSITIV )
			{
				if ( _camera )
					_camera->moveRight( shift );
			}
			else
			{
				if ( _camera )
					_camera->moveLeft( shift );
			}
		}

		if ( _zDirection != eAxisDirection::NONE )
		{
			if ( _zDirection == eAxisDirection::POSITIV )
			{
				if ( _camera )
					_camera->moveAhead( shift );
			}
			else
			{
				if ( _camera )
					_camera->moveBack( shift );
			}
		}

		if ( _yDirection != eAxisDirection::NONE )
		{
			if ( _yDirection == eAxisDirection::POSITIV )
			{
				if ( _camera )
					_camera->moveUp( shift );
			}
			else
			{
				if ( _camera )
					_camera->moveDown( shift );
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
		else if ( aKeyCode == GLFW_KEY_ESCAPE )
		{
			getGLContext()->setWindowShouldClose();
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

			_mousePos.x = static_cast<float>(posX);
			_mousePos.y = static_cast<float>(posY);
		}
	
		GLSandbox::Vec newMousePos( posX, posY );
		GLSandbox::Vec moveDelta = _mousePos - newMousePos;
		moveDelta *= _cameraRotateSensitivity;

		if ( _camera )
		{
			_camera->spinPitch( moveDelta.y );
			_camera->spinYaw( moveDelta.x );
		}

		_mousePos = newMousePos;
	}
	void CameraMovementController::onWheelScrolled( float xoffset, float yoffset )
	{
		_fovAngle += yoffset;

		auto wndSize = getGLContext()->getWindowSize();

		if ( _camera )
			_camera->setProjection( glm::perspective( glm::radians(_fovAngle), wndSize.x/wndSize.y, 0.1f, 10000.0f ) );
	}
	void CameraMovementController::initWithCamera( GLSandbox::Camera* camera )
	{
		_camera = camera;

		auto wndSize = getGLContext()->getWindowSize();
		GLSandbox::Mat4 projection = glm::perspective( glm::radians(_fovAngle), wndSize.x/wndSize.y, 0.1f, 10000.0f );

		if ( _camera )
		{
			_camera->setProjection( projection );

			_camera->setPosition(GLSandbox:: Vec3( 0.0f, 0.0f, 10.0f ) );
		}

		getTimeScheduler()->addUpdateFunc( std::bind( &CameraMovementController::updaeTime, this, std::placeholders::_1 ), this );

		getGLContext()->setInputListener( this );
	}

}