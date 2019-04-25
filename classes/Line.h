#ifndef Line_H
#define Line_H

#include "Primitive.h"

_VESTART


class Line : public Primitive
{

	typedef Primitive Parent;


	Vec _endPoint;

	protected:

		Line();

		virtual void actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;

		virtual GLenum getDrawElement() override;


	public:

		virtual ~Line();

		CREATE_DRAW_PRIMITIVE_FUNC(Line);

		void setEndPoint( const Vec& end );
		const Vec& getEndPoint();

};



_VEEND



#endif
