#include "Camera.h"

_USEVE

Camera::Camera()
	: _projection( 1.0f )
	, _view( 1.0f )
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
const Mat4& Camera::getView() const
{
	return _view;
}