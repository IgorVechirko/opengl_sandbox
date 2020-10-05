#ifndef ReflectionCubeTest_H
#define ReflectionCubeTest_H

#include "Scene.h"
#include "CameraMovementController.h"


namespace FuncTests
{
	class ReflectionCubeTest : public GLSandbox::Scene
	{

		CameraMovementController _cameraMovementController;

		GLSandbox::Node* _cube; 

	protected:

		virtual bool onInit() override;

		virtual void update( float deltaTime ) override;

	public:

		ReflectionCubeTest();
		virtual ~ReflectionCubeTest();

	};

}


#endif
