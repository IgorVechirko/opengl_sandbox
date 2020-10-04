#ifndef CustomFrameBuffer_H
#define CustomFrameBuffer_H

#include "Node.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{

	class CustomFrameBuffer 
		: public Node
		, public ShaderProtocol
	{

		GLuint _fbo;

		GLuint _colorBuffer;
		GLuint _depthStencilBuffer;

		VertexArrayObject _arrayBuffer;


	protected:

		virtual bool onInit() override;

		virtual void draw( const Mat4& trnasform ) override;
		

	public:

		CustomFrameBuffer();
		virtual ~CustomFrameBuffer();
		MAKE_UNCOPYABLE(CustomFrameBuffer);

		void bind();
		void unbind();

		void onBeforeStartDraw();
		void onDrawFinish();

	};

}


#endif