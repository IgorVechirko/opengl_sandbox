#ifndef DirectLightTest_H
#define DirectLightTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class DirectLightTest : public GLSandbox::Scene
	{

		CameraMovementController _movementController;

		virtual bool onInit() override;

	public:

		DirectLightTest();
		virtual ~DirectLightTest();

	};

}


#endif