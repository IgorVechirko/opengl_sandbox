#include "PointLightSource.h"

#include "ShaderProgram.h"


#include "ColorCube.h"

namespace GLSandbox
{

	PointLightSource::PointLightSource()
		: _cube( nullptr )
	{
	}
	PointLightSource::~PointLightSource()
	{
	}
	bool PointLightSource::onInit()
	{
		_cube = createNode<ColorCube>();
		_cube->setCubeSize( 50.0f );
		_cube->setColor( RGBA( _lightProperties.diffuse.r, _lightProperties.diffuse.g, _lightProperties.diffuse.b, 1.0f ) );
		_cube->setOriginShift( Vec3( -25.0f ) );
		addChild( _cube );

		return true;
	}
	void PointLightSource::setLightProperties( const LightProperties& properties )
	{
		_lightProperties = properties;

		if ( _cube )
		{
			_cube->setColor( RGBA( _lightProperties.diffuse.r, _lightProperties.diffuse.g, _lightProperties.diffuse.b, 1.0f ) );
		}
	}

}