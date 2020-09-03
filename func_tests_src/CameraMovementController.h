#ifndef CameraMovementController_H
#define CameraMovementController_H

#include "InputListener.h"
#include "WorkingScopeProvider.h"
#include "Camera.h"

namespace WorkingTests
{
	class CameraMovementController
		: public GLSandbox::InputListener
		, public GLSandbox::WorkingScopeProvider
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
		GLSandbox::Vec _mousePos;

		GLSandbox::Camera* _camera;


		void updaeTime( float deltaTme );

	protected:


		virtual void onKeyPressed( int aKeyCode ) override;
		virtual void onKeyPressRepeate( int aKeyCode ) override;
		virtual void onKeyReleased( int aKeyCode ) override;

		virtual void onMouseMoved( double posX, double posY ) override;

		virtual void onWheelScrolled( float xoffset, float yoffset ) override;


	public:

		CameraMovementController();
		virtual ~CameraMovementController();

		void initWithCamera( GLSandbox::Camera* camera );

	};


}


#endif