#include "TestScopeDelegat.h"

#include "GLContext.h"
#include "TestScene.h"

namespace WorkingTests
{

	GLSandbox::Scene* TestScopeDelegat::getStartScene()
	{
		return createNode<TestScene>();
	}

}