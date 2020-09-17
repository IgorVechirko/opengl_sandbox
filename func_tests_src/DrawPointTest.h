#ifndef DrawPointTest_H
#define DrawPointTest_H

#include "Scene.h"


namespace FuncTests
{
	class DrawPointTest : public GLSandbox::Scene
	{

	virtual bool onInit() override;

	public:

		DrawPointTest();
		virtual ~DrawPointTest();

	};

}


#endif