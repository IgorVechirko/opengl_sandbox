#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"

#include "CameraMovementController.h"

_VESTART


class Cube;
class Sprite;
class TestScene : public Scene
{

	typedef Scene Parent;

	CameraMovementController _cameraMovementController;

	Sprite* _mySprite;
	Node* _cube; 

protected:

	TestScene();

	virtual bool onInit() override;

	virtual void update( float deltaTime ) override;


public:

	virtual ~TestScene();

	CREATE_FUNC(TestScene);

};


_VEEND


#endif