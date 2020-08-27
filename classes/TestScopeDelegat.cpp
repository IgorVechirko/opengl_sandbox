#include "TestScopeDelegat.h"

#include "GLContext.h"
#include "TestScene.h"

GLSandbox::Scene* TestScopeDelegat::getStartScene()
{
	return createNode<GLSandbox::TestScene>();
}