#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"

#include "CameraMovementController.h"

namespace GLSandbox
{


	class Cube;
	class Sprite;
	class TestScene : public Scene
	{

		typedef Scene Parent;

		CameraMovementController _cameraMovementController;

		Sprite* _mySprite;
		Node* _cube; 

	protected:

		virtual bool onInit() override;

		virtual void update( float deltaTime ) override;


	public:

		TestScene();
		virtual ~TestScene();

	};


}


#endif