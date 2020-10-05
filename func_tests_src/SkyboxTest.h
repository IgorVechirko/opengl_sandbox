#ifndef SkyboxTest_H
#define SkyboxTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class SkyboxTest : public GLSandbox::Scene
	{

		CameraMovementController _cameraMovementController;



	protected:

		virtual bool onInit() override;

	public:

		SkyboxTest();
		virtual ~SkyboxTest();

	};

}


#endif
