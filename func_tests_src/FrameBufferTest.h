#ifndef FrameBufferTest_H
#define FrameBufferTest_H

#include "Scene.h"
#include "CameraMovementController.h"
#include "CustomFrameBuffer.h"

namespace FuncTests
{
	class FrameBufferTest : public GLSandbox::Scene
	{

		GLSandbox::CustomFrameBuffer* _frameBuffer;

		CameraMovementController _cameraMovementController;

	virtual bool onInit() override;

	virtual void onBeforeDraw() override;

	virtual void drawTraversal( const GLSandbox::Mat4& parentTransform ) override;

	public:

		FrameBufferTest();
		virtual ~FrameBufferTest();

	};

}


#endif
