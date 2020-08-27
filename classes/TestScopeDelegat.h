#ifndef TestScopeDelegat_H
#define TestScopeDelegat_H

#include "ScopeDelegate.h"

class TestScopeDelegat : public GLSandbox::ScopeDelegate
{

	virtual GLSandbox::Scene* getStartScene() override;

};



#endif