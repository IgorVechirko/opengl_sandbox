#ifndef LightSource_H
#define LightSource_H

#include "Node.h"


_VESTART

class ShaderProgram;
class LightSource : public Node
{

	typedef Node Parent;

	std::vector<GLfloat> _vertices;
	std::vector<GLuint> _indices;
	bool _verticesDirty;

	GLuint _vbo;
	GLuint _vao;
	GLuint _ebo;

	glm::vec4 _lightColor;

	ShaderProgram* _shader;


	void updateVertices();

	void setShaderProgram( ShaderProgram* program );

	protected:

		LightSource();

		virtual bool init() override;

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		virtual ~LightSource();

		CREATE_FUNC(LightSource);


		virtual void setSize( const Size& size ) override;

		void setLightColor( const glm::vec4& color );
		const glm::vec4& getLightColor();
};


_VEEND	

#endif
