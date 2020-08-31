#ifndef ColorCube_H
#define ColorCube_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayBuffer.h"

namespace GLSandbox
{

	class ColorCube : public Node
					, public ShaderProtocol
					, public ColorProtocol
	{

		typedef Node Parent;

		VertexArrayBuffer _arrayBuffer;

		bool _verticesDirty;

		float _cubeSize;


		void updateVertices();


	protected:

		virtual bool onInit() override;

		virtual void draw( GLRender* render, const Mat4& parentTransform ) override;


	public:

		ColorCube();
		virtual ~ColorCube();
		MAKE_UNCOPYABLE(ColorCube);

		virtual void setCubeSize( float size );
	};

}


#endif