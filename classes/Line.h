#ifndef Line_H
#define Line_H

#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{

	class Line : public Node
			   , public ShaderProtocol
			   , public ColorProtocol
	{
		typedef Node Parent;

		VertexArrayObject _arrayBuffer;

		Vec3 _startPos;
		Vec3 _finishPos;

		bool _verticesDirty;


		void updateVertices();

	protected:

		virtual bool onInit() override;

		virtual void draw( const Mat4& transform ) override;


	public:

		Line();
		virtual ~Line();
		MAKE_UNCOPYABLE(Line);

		void setStartPos( const Vec3& pos );
		const Vec3& getStartPos() const;

		void setFinishPos( const Vec3& pos );
		const Vec3& getFinishPos() const;


	};

}



#endif