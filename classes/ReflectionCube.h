#ifndef ReflectionCube_H
#define ReflectionCube_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{

	class ReflectionCube 
		: public Node
		, public ShaderProtocol
	{
		typedef Node Parent;

		VertexArrayObject _arrayBuffer;

		bool _verticesDirty;

		float _reflectionCubeSize;


	protected:

		virtual bool onInit() override;

		virtual void draw( const Mat4& transform ) override;

		void updateVetices();

	public:

		ReflectionCube();
		virtual ~ReflectionCube();
		MAKE_UNCOPYABLE(ReflectionCube);

		virtual void setReflectionCubeSize( float size );
	};


}


#endif