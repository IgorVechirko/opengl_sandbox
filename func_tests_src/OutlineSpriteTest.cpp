#include "OutlineSpriteTest.h"

#include "Sprite.h"
#include "ResourcesManager.h"
#include "Texture2D.h"
#include "GLContext.h"
#include "OutlineSprite.h"

using namespace GLSandbox;

namespace FuncTests
{
	OutlineSpriteTest::OutlineSpriteTest()
	{
	}
	OutlineSpriteTest::~OutlineSpriteTest()
	{
	}
	bool OutlineSpriteTest::onInit()
	{
		Scene::onInit();

		setName( "OutlineSpriteTest" );
		Console::log( getName(), ": test scene run." );


		if ( true )
		{
			auto outlineSprite1 = createScopedRefWithInitializer<OutlineSprite>( &OutlineSprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
			if ( outlineSprite1 )
			{
				outlineSprite1->setName( "1" );
				outlineSprite1->setOriginShift( Vec3( -outlineSprite1->getTexture2D()->getWidth()/2.0f, -outlineSprite1->getTexture2D()->getHeight()/2.0f, -1.0f ) );
				addChild( outlineSprite1 );
			}

			auto outlineSprite2 = createScopedRefWithInitializer<OutlineSprite>( &OutlineSprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
			if ( outlineSprite2 )
			{
				outlineSprite2->setName( "2" );
				outlineSprite2->setOriginShift( Vec3( -outlineSprite2->getTexture2D()->getWidth()/2.0f, -outlineSprite2->getTexture2D()->getHeight()/2.0f, -1.0f ) );
				outlineSprite2->setPosition( Vec3( 100.0f, -25.0f, 100.0f ) );
				addChild( outlineSprite2 );
			}
		}


		_movementController.setScope( getScope() );
		_movementController.initWithCamera( getCamera() );

		return true;
	}
}
