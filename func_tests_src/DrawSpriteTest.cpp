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

		auto sprite = createScopedRefWithInitializer<Sprite>( &Sprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
		if ( sprite )
		{
			addChild( sprite );
		}

		return true;
	}

}
