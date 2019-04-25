#ifndef Rectangle_H
#define Rectangle_H

#include "Primitive.h"

_VESTART


class Rectangle : public Primitive
{

	typedef Primitive Parent;


	Size _size;

	protected:

		Rectangle();

		virtual void  actualizeVertices(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices) override;

		virtual GLenum getDrawElement() override;


	public:

		virtual ~Rectangle();

		CREATE_DRAW_PRIMITIVE_FUNC(Rectangle);

		void setSize(const Size& size);
		const Size& getSize();

};



_VEEND



#endif
