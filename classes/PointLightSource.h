#ifndef PointLightSource_H
#define PointLightSource_H

#include "Node.h"


_VESTART

class ShaderProgram;
class PointLightSource : public Node
{

	typedef Node Parent;

	std::vector<GLfloat> _vertices;
	std::vector<GLuint> _indices;
	bool _verticesDirty;

	GLuint _vbo;
	GLuint _vao;
	GLuint _ebo;

	ShaderProgram* _shader;

	LightProperties _properties;
	LightAttenuationCoefs _attenuationCoefs;


	void updateVertices();

	void setShaderProgram( ShaderProgram* program );

	protected:

		PointLightSource();

		virtual bool init() override;

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		virtual ~PointLightSource();

		CREATE_FUNC(PointLightSource);


		virtual void setSize( const Size& size ) override;

		void setLightProperties( const LightProperties& properties );
		const LightProperties& getLightProperties();
};


_VEEND	

#endif
