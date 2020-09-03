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

		const auto& resPath = getResMng()->getResPath( "MOUNTAIN" );
		if ( resPath.empty() )
		{
			Console::log( "Test: ", getName(), " failed!!!" );
		}

		return true;
	}

}