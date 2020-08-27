#ifndef TestScopeDelegat_H
#define TestScopeDelegat_H

#include "ScopeDelegate.h"

class TestScopeDelegat : public VEngine::ScopeDelegate
{

	virtual VEngine::Scene* getStartScene() override;

};



#endif