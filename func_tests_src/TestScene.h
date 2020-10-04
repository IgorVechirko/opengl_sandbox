#ifndef TestScene_H
#define TestScene_H

#include "Scene.h"
#include "CameraMovementController.h"
#include "Sprite.h"
#include "CustomFrameBuffer.h"

namespace FuncTests
{
	class TestScene : public GLSandbox::Scene
	{

		typedef Scene Parent;

		GLSandbox::CustomFrameBuffer* _frameBuffer;

		CameraMovementController _cameraMovementController;

		GLSandbox::Sprite* _mySprite;
		GLSandbox::Node* _cube; 

	protected:

		virtual bool onInit() override;

		virtual void onBeforeDraw() override;

		virtual void update( float deltaTime ) override;

		virtual void drawTraversal( const GLSandbox::Mat4& parentTransform ) override;


	public:

		TestScene();
		virtual ~TestScene();

	};

}



#endif