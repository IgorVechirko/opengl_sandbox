#include "TestScopeDelegat.h"

#include "GLContext.h"
#include "TestScene.h"
#include "ResourcesManager.h"

namespace FuncTests
{

	void TestScopeDelegat::init()
	{
		getResMng()->parseResConfig( "resdb/resources.json" );
		getGLContext()->setScene( createNode<TestScene>() );
	}

}