#ifndef ColorCube_H
#define ColorCube_H


#include "Node.h"
#include "NodeExtentions.h"

_VESTART

class ColorCube : public Node
				, public ShaderProtocol
{

	typedef Node Parent;

	GLuint _vao;
	GLuint _vbo;
	GLuint _ebo;

	unsigned _indicesCount;

	bool _verticesDirty;

	float _cubeSize;

	RGBA _color;


	void updateVertices();


protected:

	ColorCube();

	virtual bool init() override;

	virtual void draw( GLRender* render, const Mat4& parentTransform ) override;


public:

	virtual ~ColorCube();

	CREATE_FUNC( ColorCube );

	void setColor( const RGBA& color );

	virtual void setCubeSize( float size );
};

_VEEND


#endif