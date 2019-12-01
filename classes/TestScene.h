#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"

#include "CameraMovementController.h"

_VESTART


class Cube;
class LightSource;
class Sprite;
class TestScene : public Scene
{

	Sprite* _mySprite;
	Cube* _cube; 
	LightSource* _lightSource;
	
	float _lightAngle;
	float _distToCenter;

	CameraMovementController _cameraController;

protected:

	TestScene();

	bool init() override;

	virtual void update( float deltaTime ) override;


public:

	virtual ~TestScene();

	CREATE_FUNC(TestScene);

};


_VEEND


#endif