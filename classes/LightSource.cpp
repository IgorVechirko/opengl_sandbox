#include "LightSource.h"

#include "ShaderProgram.h"
#include "Director.h"

_VESTART


LightSource::LightSource()
	: _lightColor( 1.0f, 1.0f, 1.0f, 1.0f )
	, _verticesDirty( false )
	, _vbo( 0 )
	, _vao( 0 )
	, _ebo( 0 )
	, _shader( nullptr )
{
}
LightSource::~LightSource()
{
}
void LightSource::updateVertices()
{
	_vertices.clear();
	_vertices = {	0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
					getSize().x, 0.0f, 0.0f,  1.0f, 0.0f,
					getSize().x,  getSize().x, 0.0f,  1.0f, 1.0f,
					getSize().x,  getSize().x, 0.0f,  1.0f, 1.0f,
				0.0f,  getSize().x, 0.0f,  0.0f, 1.0f,
				0.0f, 0.0f, 0.0f,  0.0f, 0.0f,

				0.0f, 0.0f,  getSize().x,  0.0f, 0.0f,
					getSize().x, 0.0f,  getSize().x,  1.0f, 0.0f,
					getSize().x,  getSize().x,  getSize().x,  1.0f, 1.0f,
					getSize().x,  getSize().x,  getSize().x,  1.0f, 1.0f,
				0.0f,  getSize().x,  getSize().x,  0.0f, 1.0f,
				0.0f, 0.0f,  getSize().x,  0.0f, 0.0f,

				0.0f,  getSize().x,  getSize().x,  1.0f, 0.0f,
				0.0f,  getSize().x, 0.0f,  1.0f, 1.0f,
				0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
				0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
				0.0f, 0.0f,  getSize().x,  0.0f, 0.0f,
				0.0f,  getSize().x,  getSize().x,  1.0f, 0.0f,

					getSize().x,  getSize().x,  getSize().x,  1.0f, 0.0f,
					getSize().x,  getSize().x, 0.0f,  1.0f, 1.0f,
					getSize().x, 0.0f, 0.0f,  0.0f, 1.0f,
					getSize().x, 0.0f, 0.0f,  0.0f, 1.0f,
					getSize().x, 0.0f,  getSize().x,  0.0f, 0.0f,
					getSize().x,  getSize().x,  getSize().x,  1.0f, 0.0f,

				0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
					getSize().x, 0.0f, 0.0f,  1.0f, 1.0f,
					getSize().x, 0.0f,  getSize().x,  1.0f, 0.0f,
					getSize().x, 0.0f,  getSize().x,  1.0f, 0.0f,
				0.0f, 0.0f,  getSize().x,  0.0f, 0.0f,
				0.0f, 0.0f, 0.0f,  0.0f, 1.0f,

				0.0f,  getSize().x, 0.0f,  0.0f, 1.0f,
					getSize().x,  getSize().x, 0.0f,  1.0f, 1.0f,
					getSize().x,  getSize().x,  getSize().x,  1.0f, 0.0f,
					getSize().x,  getSize().x,  getSize().x,  1.0f, 0.0f,
				0.0f,  getSize().x,  getSize().x,  0.0f, 0.0f,
				0.0f,  getSize().x, 0.0f,  0.0f, 1.0f 
	};

	if ( _verticesDirty )
	{
		glBindVertexArray( _vao );

		const GLfloat* vertices = &_vertices[0];
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*_vertices.size(), vertices, GL_STATIC_DRAW );

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}
void LightSource::setShaderProgram( ShaderProgram* program )
{
	if ( program )
	{
		if ( _shader )
			_shader->release();

		_shader = program;
		_shader->retain();
	}
}
bool LightSource::init()
{
	setSize( Size( 50.0f, 50.0f ) );
	updateVertices();

	_indices = { 0, 1, 2,
					1, 2, 3 };

	setShaderProgram( ShaderProgram::create( RES_PATH("ILLUMINAT_VERTEX"), RES_PATH("ILLUMINAT_FRAGMENT") ) );

	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);
	glGenBuffers(1, &_ebo);

	glBindVertexArray( _vao );

	const GLfloat* vertices = &_vertices[0];
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*_vertices.size(), vertices, GL_STATIC_DRAW );

	const GLuint* indices = &_indices[0];
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*_indices.size(), indices, GL_STATIC_DRAW );

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*5, (GLvoid*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return true;
}
void LightSource::draw( GLRender* render, const Mat4& transform )
{
	if ( _verticesDirty )
	{
		updateVertices();
		_verticesDirty = false;
	}

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glBindVertexArray(_vao);

	if( _shader )
	{
		_shader->useProgram();

		GLuint transModelLoc = glGetUniformLocation( _shader->getProgramID(), "model" );
		GLuint transViewLoc = glGetUniformLocation ( _shader->getProgramID(), "view" );
		GLuint transProjLoc = glGetUniformLocation( _shader->getProgramID(), "projection" );
		//GLuint colorLoc = glGetUniformLocation( _shader->getProgramID(), "lightColor" );

		glProgramUniformMatrix4fv( _shader->getProgramID(), transModelLoc, 1, GL_FALSE, glm::value_ptr( transform ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transViewLoc, 1, GL_FALSE, glm::value_ptr( CAMERA->getView() ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transProjLoc, 1, GL_FALSE, glm::value_ptr( CAMERA->getProjection() ) );
		//glProgramUniform4f( _shader->getProgramID(), colorLoc, _lightColor.r, _lightColor.g, _lightColor.b, _lightColor.a );

		glDrawArrays(GL_TRIANGLES, 0, _vertices.size() );
	}
	
	
	glBindVertexArray(0);
}
void LightSource::setSize( const Size& size )
{
	Parent::setSize( size );

	_verticesDirty = true;
}
void LightSource::setLightColor( const glm::vec4& color )
{
	_lightColor = color;

	if ( _shader )
	{
		auto lightColorLoc = glGetUniformLocation( _shader->getProgramID(), "lightColor" );
		glProgramUniform4f( _shader->getProgramID(), lightColorLoc, _lightColor.r, _lightColor.g, _lightColor.b, _lightColor.a );
	}

}
const glm::vec4& LightSource::getLightColor()
{
	return _lightColor;
}
_VEEND