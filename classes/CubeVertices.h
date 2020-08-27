#ifndef CubeVertices_H
#define CubeVertices_H

#include "Cube.h"
#include "NodeExtentions.h"

namespace GLSandbox
{

	class CubeVertices : public Node
					   , public Size3Protocol
					   , public ShaderProtocol
	{

	private:

		typedef Node Parent;

		GLuint _vao;
		GLuint _vbo;

		bool _verticesDirty;

	protected:

		std::vector<GLfloat> _vertices;

	private:

		void updateVertices();

	protected:

		CubeVertices();

	public:

		virtual ~CubeVertices();

		virtual void setSize3( const Size3& size ) override;

	};

}

#endif