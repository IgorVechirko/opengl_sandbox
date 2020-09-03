#ifndef MoveViewTest_H
#define MoveViewTest_H

#include "Scene.h"
#include "CameraMovementController.h"

namespace FuncTests
{
	class MoveViewTest 
		: public GLSandbox::Scene
	{

		CameraMovementController _movementController;


		virtual bool onInit() override;

	public:

		MoveViewTest();
		virtual ~MoveViewTest();

	};

}


#endif