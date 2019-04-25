#ifndef Primitive_H
#define Primitive_H


#include "VECommon.h"
#include "ShaderProgram.h"


#define CREATE_DRAW_PRIMITIVE_FUNC( __TYPE__ )\
static __TYPE__* create()\
{\
	__TYPE__* ret = new(std::nothrow) __TYPE__();\
	return ret;\
}\


_VESTART


class Primitive
{

	Vec _position;
	RGBA _color;

	std::vector<GLfloat> _vertices;
	std::vector<GLuint> _indices;
	bool _verticesDirty;

	GLuint _vbo;
	GLuint _vao;
	GLuint _ebo;

	ShaderProgram _program;


	void fillBuffers();


	protected:

		Primitive();

		virtual void actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices);

		virtual GLenum getDrawElement(){return GL_POINT;};

		void setVerticesDirty( bool isDirty );
		bool isVerticesDirty();


	public:

		virtual ~Primitive();
		

		virtual void setPosition(const Vec& position);
		virtual const Vec& getPosition();

		virtual void setColor(const RGBA& color);
		virtual const RGBA& getColor();

		void draw();

};


_VEEND


#endif