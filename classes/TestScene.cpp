#include "TestScene.h"

#include "Sprite.h"
#include "Cube.h"
#include "Director.h"
#include "PointLightSource.h"
#include "DirectLightSource.h"

_USEVE

TestScene::TestScene()
	: _mySprite( nullptr )
	, _cameraController()
{
}
TestScene::~TestScene()
{
}
bool TestScene::init()
{

	_cube = Cube::create( RES_PATH( "MOUNTAIN" ) );
	if( _cube )
	{
		addChild( _cube );
		// _cube->setPosition( Vec3( 110.0f, 110.0f, -256.0f ) );
		
		Material emerald;
		emerald.ambient = Vec3( 0.0215f, 0.1745f, 0.0215f );
		emerald.diffuse = Vec3( 0.07568f, 0.61424f, 0.07568f );
		emerald.specular = Vec3( 0.633f, 0.727811f, 0.633f );
		emerald.shininess = 32.0f;

		_cube->setMaterial( emerald );
	}


	DirectLightSource* directionLight = DirectLightSource::create();
	if ( directionLight )
	{
		directionLight->setDirection( Vec3( 0.0f, 0.0f, -1.0f ) );

		LightProperties lightProperties;
		lightProperties.ambient = Vec3( 0.2f, 0.2f, 0.2f );
		lightProperties.diffuse = Vec3( 0.5f, 0.5f, 0.5f );
		lightProperties.specular = Vec3( 1.0f, 1.0f, 1.0f );
		directionLight->setLightProperties( lightProperties );

		setDirectionLight( directionLight );
	}

	_cameraController.init();

	scheduleUpdate();

	return true;
}
void TestScene::update( float deltaTime )
{	

	_cube->setRotate( _cube->getRotate() + Vec3( 1.0f, 0.0f, 0.0f ) * 0.25f );
}