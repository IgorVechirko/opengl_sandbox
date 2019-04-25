#ifndef Point_H
#define Point_H

#include "Primitive.h"

_VESTART


class Point : public Primitive
{

	typedef Primitive Parent;


	Vec _endPoint;

	protected:

		Point();

		virtual void actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;

		virtual GLenum getDrawElement() override;


	public:

		virtual ~Point();

		CREATE_DRAW_PRIMITIVE_FUNC(Point);

};



_VEEND



#endif
