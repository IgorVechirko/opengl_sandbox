#ifndef OutlineSpriteTest_H
#define OutlineSpriteTest_H

#include "Scene.h"
#include "CameraMovementController.h"
#include "InputListener.h"

namespace FuncTests
{
	class OutlineSpriteTest 
		: public GLSandbox::Scene
		, public GLSandbox::InputListener
	{


		CameraMovementController _movementController;



	protected:

		virtual bool onInit() override;

	public:

		OutlineSpriteTest();
		virtual ~OutlineSpriteTest();

	};

}


#endif
