#ifndef DrawPrimitivesTest_H
#define DrawPrimitivesTest_H

#include "Scene.h"


namespace FuncTests
{
	class DrawPrimitivesTest : public GLSandbox::Scene
	{

	virtual bool onInit() override;

	public:

		DrawPrimitivesTest();
		virtual ~DrawPrimitivesTest();

	};

}


#endif