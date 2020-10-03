#ifndef FuncTest_H
#define FuncTest_H

#include "Scene.h"


namespace FuncTests
{
	class FuncTest : public GLSandbox::Scene
	{

	virtual bool onInit() override;

	public:

		FuncTest();
		virtual ~FuncTest();

	};

}


#endif
