#ifndef ScopeDelegate_H
#define ScopeDelegate_H


#include "Scene.h"


namespace GLSandbox
{

	class ScopeDelegate : public WorkingScopeProvider
	{

	protected:


	public:

		virtual Scene* getStartScene(){return createNode<Scene>();};

	};

}



#endif