#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"

#include "KeyboardController.h"

_VESTART


class Sprite;
class TestScene : public Scene
				, public KeyboardControllerListener
{

	Sprite* _mySprite;

protected:

	TestScene();

	bool init() override;

	virtual void update( float deltaTime ) override;

	virtual void onKeyPressed( int aKeyCode ) override;
	virtual void onKeyPressRepeate( int aKeyCode ) override;
	virtual void onKeyReleased( int aKeyCode ) override;

public:

	virtual ~TestScene();

	CREATE_FUNC(TestScene);

};


_VEEND


#endif