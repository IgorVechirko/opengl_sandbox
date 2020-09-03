#ifndef PointLightTest_H
#define PointLightTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class PointLightTest : public GLSandbox::Scene
	{

		CameraMovementController _movementController;

		virtual bool onInit() override;

	public:

		PointLightTest();
		virtual ~PointLightTest();

	};

}


#endif