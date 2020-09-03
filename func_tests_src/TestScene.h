#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"
#include "CameraMovementController.h"
#include "Sprite.h"

namespace FuncTests
{
	class TestScene : public GLSandbox::Scene
	{

		typedef Scene Parent;

		CameraMovementController _cameraMovementController;

		GLSandbox::Sprite* _mySprite;
		GLSandbox::Node* _cube; 

	protected:

		virtual bool onInit() override;

		virtual void update( float deltaTime ) override;


	public:

		TestScene();
		virtual ~TestScene();

	};

}



#endif