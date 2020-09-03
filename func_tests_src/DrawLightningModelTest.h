#ifndef DrawLightningModelTest_H
#define DrawLightningModelTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class DrawLightningModelTest : public GLSandbox::Scene
	{

		CameraMovementController _movementController;

		virtual bool onInit() override;

	public:

		DrawLightningModelTest();
		virtual ~DrawLightningModelTest();

	};

}


#endif