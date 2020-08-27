#ifndef ScopeDelegate_H
#define ScopeDelegate_H


#include "Scene.h"

_VESTART

class ScopeDelegate : public WorkingScopeProvider
{

protected:


public:

	virtual Scene* getStartScene(){return createNode<Scene>();};

};

_VEEND



#endif