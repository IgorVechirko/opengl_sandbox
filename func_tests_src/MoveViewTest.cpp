#include "MoveViewTest.h"

#include "Line.h"
#include "ColorCube.h"

using namespace GLSandbox;

namespace FuncTests
{
	MoveViewTest::MoveViewTest()
	{
	}
	MoveViewTest::~MoveViewTest()
	{
	}
	bool MoveViewTest::onInit()
	{
		Scene::onInit();

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

		_movementController.setScope( getScope() );
		_movementController.initWithCamera( getCamera() );

		return true;
	}

}
