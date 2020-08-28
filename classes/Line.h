#ifndef Line_H
#define Line_H

#include "Node.h"
#include "NodeExtestions.h"

namespace GLSandbox
{

	class Line : public Node
			   , public ShaderProtocol
			   , public ColorProtocol
	{
		typedef Node Parent;

		GLuint _vao;
		GLuint _vbo;

		Vec3 _startPos;
		Vec3 _finishPos;

		bool _verticesDirty;


		void updateVertices();

	protected:

		virtual bool onInit() override;

		virtual void draw( GLRender* render, const Mat4& transform ) override;


	public:

		Line();
		virtual ~Line();

		void setStartPos( const Vec3& pos );
		const Vec3& getStartPos() const;

		void setFinishPos( const Vec3& pos );
		const Vec3& getFinishPos() const;


	};

}



#endif