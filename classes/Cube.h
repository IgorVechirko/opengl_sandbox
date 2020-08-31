#ifndef Cube_H
#define Cube_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayBuffer.h"

namespace GLSandbox
{

	class Texture2D;
	class ShaderProgram;
	class Cube 
		: public Node
		, public MaterialProtocol
		, public ShaderProtocol
	{
		typedef Node Parent;

		VertexArrayBuffer _arrayBuffer;

		bool _verticesDirty;

		float _cubeSize;


	protected:

		virtual bool onInit() override;

		virtual void draw( GLRender* render, const Mat4& transform ) override;

		void updateVetices();

	public:

		Cube();
		virtual ~Cube();
		MAKE_UNCOPYABLE(Cube);

		virtual void setCubeSize( float size );
	};


}


#endif