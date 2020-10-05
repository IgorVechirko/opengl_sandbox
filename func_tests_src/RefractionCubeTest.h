#ifndef RefractionCubeTest_H
#define RefractionCubeTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class RefractionCubeTest : public GLSandbox::Scene
	{

		CameraMovementController _cameraMovementController;

		GLSandbox::Node* _cube; 

	protected:

		virtual bool onInit() override;

		virtual void update( float deltaTime ) override;

	public:

		RefractionCubeTest();
		virtual ~RefractionCubeTest();

	};

}


#endif
