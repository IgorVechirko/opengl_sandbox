#ifndef RefractionCube_H
#define RefractionCube_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{

	class RefractionCube 
		: public Node
		, public ShaderProtocol
	{
		typedef Node Parent;

		VertexArrayObject _arrayBuffer;

		bool _verticesDirty;

		float _RefractionCubeSize;

		float _refractCoef;


	protected:

		virtual bool onInit() override;

		virtual void draw( const Mat4& transform ) override;

		void updateVetices();

	public:

		RefractionCube();
		virtual ~RefractionCube();
		MAKE_UNCOPYABLE(RefractionCube);

		virtual void setRefractionCubeSize( float size );

		void setRefractCoef( float coef );
		float getRefractCoef();
	};


}


#endif