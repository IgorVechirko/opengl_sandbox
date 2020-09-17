#ifndef Point_H
#define Point_H

#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{

	class Point 
		: public Node
		, public ShaderProtocol
		, public ColorProtocol
	{
		VertexArrayObject _arrayBuffer;


		float _size;

	public:

		Point();
		virtual ~Point();
		MAKE_UNCOPYABLE(Point);

		virtual bool onInit() override;

		virtual void draw( const Mat4& transform ) override;


		void setSize( float radius );
		float getSize() const;



	};


}



#endif