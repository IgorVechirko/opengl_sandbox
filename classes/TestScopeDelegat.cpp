#include "TestScopeDelegat.h"

#include "GLContext.h"
#include "TestScene.h"

VEngine::Scene* TestScopeDelegat::getStartScene()
{
	return createNode<VEngine::TestScene>();
}