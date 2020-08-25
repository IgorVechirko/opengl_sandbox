#ifndef Line_H
#define Line_H

#include "Node.h"
#include "NodeExtentions.h"

_VESTART

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

	Line();

	virtual bool onInit() override;

	virtual void draw( GLRender* render, const Mat4& transform ) override;


public:

	virtual ~Line();

	CREATE_FUNC( Line );

	void setStartPos( const Vec3& pos );
	const Vec3& getStartPos();

	void setFinishPos( const Vec3& pos );
	const Vec3& getFinishPos();

	


};




_VEEND


#endif