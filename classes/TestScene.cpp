#include "TestScene.h"

#include "Sprite.h"
#include "Cube.h"
#include "Director.h"
#include "LightSource.h"

_USEVE

TestScene::TestScene()
	: _mySprite( nullptr )
	, _cameraController()
	, _lightSource( nullptr )
	, _lightAngle( 0.0f )
	, _distToCenter( 0.0f )
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
		_cube->setPosition( Vec3( 110.0f, 110.0f, -256.0f ) );
	}


	_lightSource = LightSource::create();
	if ( _lightSource )
	{
		addChild( _lightSource );
		_lightSource->setLightColor( glm::vec4( 1.0, 1.0f, 1.0f, 1.0f ) );
		_lightSource->setPosition( Vec3( -500.0f, 100.0f, 200.0f ) );

		_distToCenter = glm::sqrt( glm::pow( _lightSource->getPosition().x, 2) + glm::pow(_lightSource->getPosition().y, 2) );

		RENDER->setLightSource( _lightSource );
	}


	_cameraController.init();

	scheduleUpdate();

	return true;
}
void TestScene::update( float deltaTime )
{

	if ( _lightSource )
	{
		_lightAngle += 180.0f / 360.0f;

		auto lightNewPos = _lightSource->getPosition();
		float SIN = glm::sin( ( glm::radians(_lightAngle) ) );
		float COS = glm::cos( ( glm::radians(_lightAngle) ) );

		lightNewPos.x = _distToCenter * SIN;
		lightNewPos.y = _distToCenter * COS;

		_lightSource->setPosition( lightNewPos );
	}
	
}