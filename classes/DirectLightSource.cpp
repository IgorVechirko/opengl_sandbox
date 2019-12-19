#include "DirectLightSource.h"



_USEVE


DirectLightSource::DirectLightSource()
	: _direction( 0.0f, 0.0f, 0.0f )
{
}
DirectLightSource::~DirectLightSource()
{
}
void DirectLightSource::setDirection( const Vec3& direction )
{
	_direction = direction;
}
const Vec3& DirectLightSource::getDirection()
{
	return _direction;
}
void DirectLightSource::setLightProperties( const LightProperties& properties )
{
	_lightProperties = properties;
}
const LightProperties& DirectLightSource::getLightProperties()
{
	return _lightProperties;
}