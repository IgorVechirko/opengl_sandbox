#ifndef FlashlightTest_H
#define FlashlightTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class FlashlightTest : public GLSandbox::Scene
	{

		CameraMovementController _movementController;

		virtual bool onInit() override;

	public:

		FlashlightTest();
		virtual ~FlashlightTest();

	};

}


#endif