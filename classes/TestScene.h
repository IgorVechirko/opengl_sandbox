#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"

#include "CameraMovementController.h"

_VESTART


class Cube;
class Sprite;
class TestScene : public Scene
				, public CameraMovementController
{

	typedef Scene Parent;

	Sprite* _mySprite;
	Cube* _cube; 

protected:

	TestScene();

	bool init() override;

	virtual void update( float deltaTime ) override;

	virtual Camera* getCamera() override;


public:

	virtual ~TestScene();

	CREATE_FUNC(TestScene);

};


_VEEND


#endif