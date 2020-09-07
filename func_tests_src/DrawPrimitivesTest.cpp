#include "DrawPrimitivesTest.h"

#include "Line.h"
#include "ColorCube.h"

using namespace GLSandbox;

namespace FuncTests
{
	DrawPrimitivesTest::DrawPrimitivesTest()
	{
	}
	DrawPrimitivesTest::~DrawPrimitivesTest()
	{
	}
	bool DrawPrimitivesTest::onInit()
	{
		Scene::onInit();
		setName( "DrawPrimitivesTest" );
		Console::log( getName(), ": test scene run." );

		auto line = createNode<Line>();
		if ( line )
		{
			line->setFinishPos( Vec3(1000.0f, 1000.0f, 0.0f) );
			line->setColor( RGBA::GREEN );
			addChild( line );
		}

		auto cube = createNode<ColorCube>();
		if ( cube )
		{
			cube->setPosition( Vec3( 0.0f, 100.0f, 0.0f ) );
			cube->setCubeSize( 250.f );
			cube->setColor( RGBA::RED );
			addChild( cube );
		}

		return true;
	}

}