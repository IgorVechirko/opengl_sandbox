#ifndef DrawModelTest_H
#define DrawModelTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class DrawModelTest : public GLSandbox::Scene
	{

		CameraMovementController _movementController;

		virtual bool onInit() override;

	public:

		DrawModelTest();
		virtual ~DrawModelTest();

	};

}


#endif