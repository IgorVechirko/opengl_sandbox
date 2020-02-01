#include "TestScene.h"

#include "Sprite.h"
#include "Cube.h"
#include "Director.h"
#include "PointLightSource.h"
#include "DirectLightSource.h"
#include "ColorCube.h"
#include "Line.h"
#include "AxisesOrigin.h"
#include "PointLightSource.h"
#include "Flashlight.h"

_USEVE

TestScene::TestScene()
	: _mySprite( nullptr )
{
}
TestScene::~TestScene()
{
}
bool TestScene::init()
{
	Parent::init();

	auto origin = AxisesOrigin::create();
	addChild( origin );

	Material emerald;
	emerald.ambient = Vec3( 0.0215f, 0.1745f, 0.0215f );
	emerald.diffuse = Vec3( 0.07568f, 0.61424f, 0.07568f );
	emerald.specular = Vec3( 0.633f, 0.727811f, 0.633f );
	emerald.shininess = 32.0f;

	if( false )
	{
		for( int i = 0; i < 3; i++ )
		{
			for( int j = 0; j < 3; j++ )
			{
				for( int z = 0; z < 3; z++ )
				{
					auto cube = Cube::create(	RES_PATH( "MOUNTAIN" ) );
					cube->setMaterial( emerald );
					cube->setPosition( Vec3( 1400.0f*i, 1400.0f*j, -1400.0f*z ) );
					cube->setRotate( Vec3( 10.0f*i, 10.0f*j, 10.0f*z ) );
					cube->setOriginShift( Vec3( -200.0f ) );

					addChild( cube );
				}
			}
		}
	}

	{
		auto cube = Cube::create(	RES_PATH( "MOUNTAIN" ) );
		cube->setMaterial( emerald );
		cube->setPosition( Vec3( 0.0f, 0.0f, -500.0f ) );
		cube->setOriginShift( Vec3( -200.0f ) );
		cube->setScale( Vec3( 3.0f, 3.0f, 3.0f ) );

		addChild( cube );
		_cube = cube;
	}

	if ( false )
	{
		auto colorCube = ColorCube::create();

		//colorCube->setColor( RGBA::RED );
		colorCube->setCubeSize( 100.0f );
		colorCube->setOriginShift( Vec3( -50.0f, -50.0f, -50.0f ) );
		colorCube->setPosition ( Vec3( 100.0f, 100.0f, 100.0f ) );
		//colorCube->setScale( Vec3( 0.5f, 0.5f, 0.5f ) );

		addChild( colorCube );

		_cube = colorCube;
	}

	LightProperties lightProperties;
	lightProperties.ambient = Vec3( 0.2f, 0.2f, 0.2f );
	lightProperties.diffuse = Vec3( 0.5f, 0.5f, 0.5f );
	lightProperties.specular = Vec3( 1.0f, 1.0f, 1.0f );

	LightAttenuationCoefs attenuation;
	attenuation.constant = 1.0f;
	attenuation.linear = 0.000014f;
	attenuation.quadratic = 0.0000007f;

	
	if ( true )
	{
		DirectLightSource* directionLight = DirectLightSource::create();
		directionLight->setPosition( Vec3( 0.0f, 0.0f, 1000.0f ) );
		directionLight->setDirection( Vec3( 1.0f, 0.0f, 0.0f ) );

		
		directionLight->setLightProperties( lightProperties );

		setDirectionLight( directionLight );
	}

	if ( true )
	{
		float dist = 400.0f;
		std::vector<Vec3> lightsPositions;
		lightsPositions.push_back( Vec3( 2.0f*dist, 2.0f*dist, -2.0f*dist ) );
		/*lightsPositions.push_back( Vec3( -dist, 0.0f, dist ) );
		lightsPositions.push_back( Vec3( -dist, 0.0f, 0.0f ) );
		lightsPositions.push_back( Vec3( -dist, 0.0f, -dist ) );
		lightsPositions.push_back( Vec3( 0.0f, 0.0f, -dist ) );
		lightsPositions.push_back( Vec3( dist, 0.0f, -dist ) );
		lightsPositions.push_back( Vec3( dist, 0.0f, 0.0f ) );
		lightsPositions.push_back( Vec3( dist, 0.0f, dist ) );*/

		for( const auto& pos : lightsPositions )
		{
			auto pointLight = PointLightSource::create();
			pointLight->setLightProperties( lightProperties );
			pointLight->setAttenuation( attenuation );
			pointLight->setPosition( pos );

			addPointLight( pointLight );
		}
	}

	if ( true )
	{
		auto light = Flashlight::create();

		light->setAttenuation( attenuation );
		light->setLightProperties( lightProperties );
		light->setPosition( Vec3( 0.0f, 0.0f, 600.0f ) );
		light->setDirection( Vec3( 0.0f, 0.0f, -1.0f ) );
		light->setCutOffAngle( 12.5f );
		light->setOuterCutOffAngle( 17.0f );
		
		addFlashlight( light );
	}



	CameraMovementController::init();

	scheduleUpdate();

	return true;
}
void TestScene::update( float deltaTime )
{	
	if( _cube )
	{
		/*if ( _cube->getScale().x <= -1.0f )
		{
			_cube->setScale( Vec3( 1.0f ) );
		}

		_cube->setScale( _cube->getScale() - Vec3( 0.1f ) * deltaTime );

		*/_cube->setRotate( _cube->getRotate() + Vec3( 20.0f, 0.0f, 20.0f ) * deltaTime );
	}
}
Camera* TestScene::getCamera()
{
	return Parent::getCamera();
}