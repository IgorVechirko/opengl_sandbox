#ifndef DrawSpriteTest_H
#define DrawSpriteTest_H

#include "Scene.h"


namespace FuncTests
{
	class DrawSpriteTest : public GLSandbox::Scene
	{

	virtual bool onInit() override;

	public:

		DrawSpriteTest();
		virtual ~DrawSpriteTest();

	};

}


#endif