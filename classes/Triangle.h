#ifndef Triangle_H
#define Triangle_H

#include "Primitive.h"

_VESTART


class Triangle : public Primitive
{

	typedef Primitive Parent;


	Vec _point1;
	Vec _point2;

	protected:

		Triangle();

		virtual void  actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;

		virtual GLenum getDrawElement() override;


	public:

		virtual ~Triangle();

		CREATE_DRAW_PRIMITIVE_FUNC(Triangle);

		void setPoints(const Vec& point1, const Vec& point2);
		const Vec& getPoint1();
		const Vec& getPoint2();

};



_VEEND



#endif
