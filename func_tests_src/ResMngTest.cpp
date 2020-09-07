#include "ResMngTest.h"

#include "ResourcesManager.h"

using namespace GLSandbox;

namespace FuncTests
{
	ResMngTest::ResMngTest()
	{
	}
	ResMngTest::~ResMngTest()
	{
	}
	bool ResMngTest::onInit()
	{
		Scene::onInit();

		setName( "ResMngTest" );
		Console::log( getName(), ": test scene run." );

		const auto& resPath = getResMng()->getResPath( "MOUNTAIN" );
		if ( resPath.empty() )
		{
			Console::log( "Test: ", getName(), " failed!!!" );
		}

		return true;
	}

}