#ifndef ColorCube_H
#define ColorCube_H


#include "Node.h"
#include "NodeExtentions.h"

_VESTART

class ColorCube : public Node
				, public ShaderProtocol
				, public ColorProtocol
{

	typedef Node Parent;

	GLuint _vao;
	GLuint _vbo;
	GLuint _ebo;

	unsigned _indicesCount;

	bool _verticesDirty;

	float _cubeSize;


	void updateVertices();


protected:

	virtual bool onInit() override;

	virtual void draw( GLRender* render, const Mat4& parentTransform ) override;


public:

	ColorCube();
	virtual ~ColorCube();

	virtual void setCubeSize( float size );
};

_VEEND


#endif