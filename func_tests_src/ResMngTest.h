#ifndef ResMngTest_H
#define ResMngTest_H

#include "Scene.h"


namespace FuncTests
{
	class ResMngTest : public GLSandbox::Scene
	{

	virtual bool onInit() override;

	public:

		ResMngTest();
		virtual ~ResMngTest();

	};

}


#endif