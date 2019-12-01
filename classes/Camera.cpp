#include "Camera.h"

_USEVE

Camera::Camera()
	: _projection( 1.0f )
	, _view( 1.0f )
	, _cameraPos( 0.0f, 0.0f, 1.0f )
	, _cameraFront( 0.0f, 0.0f, -1.0f )
	, _cameraUp( 0.0f, 1.0f, 0.0f )
	, _cameraPitch( 0.0f )
	, _cameraYaw( -90.0f )
	, _cameraRoll( 0.0f )
	, _viewDirty( false )
{
}
Camera::~Camera()
{
}
void Camera::setProjection( const Mat4& projection )
{
	_projection = projection;
}
const Mat4& Camera::getProjection() const
{
	return _projection;
}
void Camera::setView( const Mat4& view )
{
	_view = view;
}
const Mat4& Camera::getView()
{
	if ( _viewDirty )
	{
		_viewDirty = false;

		_cameraFront.x = glm::cos( glm::radians(_cameraPitch)) * glm::cos( glm::radians(_cameraYaw) );
		_cameraFront.y = glm::sin( glm::radians(_cameraPitch) );
		_cameraFront.z = glm::cos( glm::radians(_cameraPitch) ) * glm::sin( glm::radians(_cameraYaw) );

		_view = glm::lookAt( _cameraPos, _cameraPos + _cameraFront, _cameraUp );
	}

	return _view;
}
void Camera::setCameraPos( const Vec3& pos )
{
	_cameraPos = pos;
	_viewDirty = true;
}
const Vec3& Camera::getCameraPos() const
{
	return _cameraPos;
}
void Camera::moveAhead( float shift )
{
	_cameraPos += shift * _cameraFront;
	_viewDirty = true;
}
void Camera::moveBack( float shift )
{
	_cameraPos -= shift * _cameraFront;
	_viewDirty = true;
}
void Camera::moveRight( float shift )
{
	_cameraPos += glm::normalize( glm::cross( _cameraFront, _cameraUp ) ) * shift;
	_viewDirty = true;
}
void Camera::moveLeft( float shift )
{
	_cameraPos -= glm::normalize( glm::cross( _cameraFront, _cameraUp ) ) * shift;
	_viewDirty = true;
}
void Camera::moveUp( float shift )
{
	_cameraPos += shift * _cameraUp;
	_viewDirty = true;
}
void Camera::moveDown( float shift )
{
	_cameraPos -= shift * _cameraUp;
	_viewDirty = true;
}
void Camera::spinPitch( float shift )
{
	if ( shift > 0.0f && _cameraPitch < 90.0f )
	{
		_viewDirty = true;
		_cameraPitch += shift;
	}
	else if ( shift < 0.0f && _cameraPitch > -90.0f )
	{
		_viewDirty = true;
		_cameraPitch += shift;
	}
}
void Camera::spinYaw( float shift )
{
	_cameraYaw -= shift;
	_viewDirty = true;

	if ( _cameraYaw > 360.0f )
	{
		_cameraYaw -= 360.0f;
	}
	else if ( _cameraYaw < -360.0f )
	{
		_cameraYaw += 360.0f;
	}
}