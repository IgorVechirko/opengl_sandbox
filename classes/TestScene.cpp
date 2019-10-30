#include "TestScene.h"

#include "Sprite.h"
#include "Cube.h"
#include "Director.h"

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
	_mySprite = Sprite::create( RES_PATH("MOUNTAIN") );

	if ( _mySprite )
	{
		addChild( _mySprite );
		_mySprite->setPosition( Vec3( 0.0f, 0.0f, 0.0f ) );

		_mySprite->setRotate( Vec3( 0.0f, 0.0f, 90.0f ) );
	}

	auto smallImage = Cube::create( RES_PATH( "SMALL_IMAGE" ) );
	if( smallImage )
	{
		addChild( smallImage );
		smallImage->setPosition( Vec3( 110.0f, 110.0f, 1.0f ) );
	}

	auto wndSize = VIEW->getWindowSize();
	Mat4 projection = glm::perspective( glm::radians(45.0f), wndSize.x/wndSize.y, 0.1f, 10000.0f );
	Mat4 view(1.0f);
	view = glm::translate( view, Vec3(0.0f, 0.0f, -927.0f ) );
	
	CAMERA->setView( view );
	CAMERA->setProjection( projection );

	scheduleUpdate();

	return true;
}
void TestScene::update( float deltaTime )
{
	if ( _mySprite )
	{
		auto rotation = _mySprite->getRotate();
		rotation.z += ( deltaTime * 10.0f );

		_mySprite->setRotate( rotation );
	}
}