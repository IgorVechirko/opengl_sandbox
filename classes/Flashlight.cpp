#include "FlashLight.h"

#include "ColorCube.h"

_USEVE

Flashlight::Flashlight()
	: _cube( nullptr )
	, _cutOffAngle( 0.0f )
	, _outerCutOffAngle( 0.0f )
{
}
Flashlight::~Flashlight()
{
}
bool Flashlight::onInit()
{
	_cube = createNode<ColorCube>();
	_cube->setCubeSize( 50.0f );
	_cube->setColor( RGBA( _lightProperties.diffuse.r, _lightProperties.diffuse.g, _lightProperties.diffuse.b, 1.0f ) );
	_cube->setOriginShift( Vec3( -25.0f ) );
	addChild( _cube );

	return true;
}
void Flashlight::setLightProperties( const LightProperties& properties )
{
	_lightProperties = properties;

	if ( _cube )
	{
		_cube->setColor( RGBA( _lightProperties.diffuse.r, _lightProperties.diffuse.g, _lightProperties.diffuse.b, 1.0f ) );
	}
}
void Flashlight::setDirection( const Vec3& direction )
{
	_direction = glm::normalize(direction);
}
const Vec3& Flashlight::getDirection()
{
	return _direction;
}
void Flashlight::setCutOffAngle( float angle )
{
	if ( angle >= 0.0f )
	{
		_cutOffAngle = angle;

		if ( _outerCutOffAngle < _cutOffAngle )
		{
			_outerCutOffAngle = _cutOffAngle;
		}
	}
}
float Flashlight::getCutOffAngle()
{
	return _cutOffAngle;
}
void Flashlight::setOuterCutOffAngle( float angle )
{
	if ( angle >= 0.0f )
	{
		_outerCutOffAngle = angle;

		if ( _outerCutOffAngle - _cutOffAngle < 0.0f )
		{
			_outerCutOffAngle = _cutOffAngle;
		}
	}
}
float Flashlight::getOuterCutOffAngle()
{
	return _outerCutOffAngle;
}