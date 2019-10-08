#include "TestScene.h"

#include "Sprite.h"
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

		_mySprite->setPosition( Vec3( 10.0f, 10.0f, 0.0f ) );

		auto smallImage = Sprite::create( RES_PATH( "SMALL_IMAGE" ) );
		if( smallImage )
		{
			_mySprite->addChild( smallImage );
			smallImage->setPosition( Vec3( 200.0f, 20.0f, 0.0f ) );
		}
	}

	return true;
}