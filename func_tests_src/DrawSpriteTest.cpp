#include "DrawSpriteTest.h"

#include "Sprite.h"
#include "ResourcesManager.h"

using namespace GLSandbox;

namespace FuncTests
{
	DrawSpriteTest::DrawSpriteTest()
	{
	}
	DrawSpriteTest::~DrawSpriteTest()
	{
	}
	bool DrawSpriteTest::onInit()
	{
		Scene::onInit();
		setName( "DrawSpriteTest" );
		Console::log( getName(), ": test scene run." );

		auto sprite = createScopedRefWithInitializer<Sprite>( &Sprite::initWithFilePath, getResMng()->getResPath( "GRASS" ) );
		if ( sprite )
		{
			addChild( sprite );
		}

		return true;
	}

}
