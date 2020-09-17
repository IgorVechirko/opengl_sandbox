#include "DrawPointTest.h"

#include "Point.h"
#include "ResourcesManager.h"
#include "GLContext.h"

using namespace GLSandbox;

namespace FuncTests
{
	DrawPointTest::DrawPointTest()
	{
	}
	DrawPointTest::~DrawPointTest()
	{
	}
	bool DrawPointTest::onInit()
	{
		Scene::onInit();
		setName( "DrawPointTest" );
		Console::log( getName(), ": test scene run." );

		auto point = createNode<Point>();
		if ( point )
		{
			point->setPosition( Vec3( getGLContext()->getWindowSize().x/3.0f, getGLContext()->getWindowSize().y/3.0f, 0.0f ) );
			point->setSize( 10.0f );
			point->setColor( RGBA::RED );

			addChild( point );
		}

		return true;
	}

}
