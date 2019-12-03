#include "Cube.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Director.h"
#include "LightSource.h"

_USEVE

Cube::Cube()
	: _texture( nullptr )
	, _shader( nullptr )
	, _vbo( 0 )
	, _vao( 0 )
	, _ebo( 0 )
{
}
Cube::~Cube()
{
}
Cube* Cube::create( const std::string& filePath )
{
	Cube* ret = new Cube();

	if ( ret && ret->init( filePath ) )
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		delete ret;
		return nullptr;
	}
}
void Cube::updateVertices( const Size& size )
{
}
bool Cube::init( const std::string& filePath )
{	
	auto texture = Texture2D::create( filePath );

	if ( texture )
	{
		setTexture( texture );
		return true;
	}
	else
		return false;
}
void Cube::setShaderProgram( ShaderProgram* program )
{
	if ( program )
	{
		if ( _shader )
			_shader->release();

		_shader = program;
		_shader->retain();
	}
}
void Cube::setTexture( Texture2D* texture )
{
	if ( texture )
	{
		if ( _texture )
			_texture->release();

		_texture = texture;
		_texture->retain();

		Size textSize( _texture->getWidth(), _texture->getHeight() );


		_vertices = {	0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
						 textSize.x, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,

						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f,  0.0f,  1.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
						0.0f,  textSize.x,  textSize.x,  0.0f, 1.0f,  0.0f,  0.0f,  1.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f,

						0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
						0.0f,  textSize.x, 0.0f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
						0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
						 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
						 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
						 textSize.x, 0.0f,  textSize.x,  0.0f, 0.0f,  1.0f,  0.0f,  0.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f,

						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,  0.0f, -1.0f,  0.0f,
						 textSize.x, 0.0f, 0.0f,  1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f, -1.0f,  0.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,  0.0f, -1.0f,  0.0f,

						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,  0.0f,  1.0f,  0.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
						 textSize.x,  textSize.x,  textSize.x, 1.0f, 0.0f,  0.0f,  1.0f,  0.0f,
						 textSize.x,  textSize.x,  textSize.x, 1.0f, 0.0f,  0.0f,  1.0f,  0.0f,
						0.0f,  textSize.x,  textSize.x,  0.0f, 0.0f,  0.0f,  1.0f,  0.0f,
						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,  0.0f,  1.0f,  0.0f, };

		_indices = { 0, 1, 2,
					 1, 2, 3 };

		setShaderProgram( ShaderProgram::create( RES_PATH("CUBE_VERTEX"), RES_PATH("CUBE_FRAGMENT") ) );

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

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(3*sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(5*sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}
void Cube::draw( GLRender* render, const Mat4& transform )
{
	if ( _texture )
		glBindTexture(GL_TEXTURE_2D, _texture->getTextureID() );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	glBindVertexArray(_vao);

	if( _shader )
	{
		_shader->useProgram();

		GLuint transModelLoc = glGetUniformLocation( _shader->getProgramID(), "model" );
		GLuint transViewLoc = glGetUniformLocation ( _shader->getProgramID(), "view" );
		GLuint transProjLoc = glGetUniformLocation( _shader->getProgramID(), "projection" );

		GLuint cameraPosLoc = glGetUniformLocation( _shader->getProgramID(), "cameraPos" );

		GLuint materialAmbientLoc = glGetUniformLocation( _shader->getProgramID(), "material.ambient" );
		GLuint materialDiffuseLoc = glGetUniformLocation( _shader->getProgramID(), "material.diffuse" );
		GLuint materialSpecularLoc = glGetUniformLocation( _shader->getProgramID(), "material.specular" );
		GLuint materialShininessLoc = glGetUniformLocation( _shader->getProgramID(), "material.shininess" );

		GLuint lightPropAmbientLoc = glGetUniformLocation( _shader->getProgramID(), "lightProperties.ambient" );
		GLuint lightPropDiffuseLoc = glGetUniformLocation( _shader->getProgramID(), "lightProperties.diffuse" );
		GLuint lightPropSpecularLoc = glGetUniformLocation( _shader->getProgramID(), "lightProperties.specular" );
		GLuint lightPropPosLoc = glGetUniformLocation( _shader->getProgramID(), "lightProperties.pos" );


		LightProperties lightProperties;
		glm::vec3 lightSourcePos( 0.0f, 0.0f, 0.0f );
		auto lightSource = RENDER->getLightSource();
		if ( lightSource )
		{
			lightProperties = lightSource->getLightProperties();
			lightSourcePos = lightSource->getPosition();
		}

		auto& cameraPos = CAMERA->getCameraPos();

		glProgramUniformMatrix4fv( _shader->getProgramID(), transModelLoc, 1, GL_FALSE, glm::value_ptr( transform ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transViewLoc, 1, GL_FALSE, glm::value_ptr( CAMERA->getView() ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transProjLoc, 1, GL_FALSE, glm::value_ptr( CAMERA->getProjection() ) );
		glProgramUniform3f( _shader->getProgramID(), cameraPosLoc, cameraPos.x, cameraPos.y, cameraPos.z );

		glProgramUniform3f( _shader->getProgramID(), materialAmbientLoc, _material.ambient.r, _material.ambient.g, _material.ambient.b );
		glProgramUniform3f( _shader->getProgramID(), materialDiffuseLoc, _material.diffuse.r, _material.diffuse.g, _material.diffuse.b );
		glProgramUniform3f( _shader->getProgramID(), materialSpecularLoc, _material.specular.r, _material.specular.g, _material.specular.b );
		glProgramUniform1f( _shader->getProgramID(), materialShininessLoc, _material.shininess );

		glProgramUniform3f( _shader->getProgramID(), lightPropAmbientLoc, lightProperties.ambient.r, lightProperties.ambient.g, lightProperties.ambient.b );
		glProgramUniform3f( _shader->getProgramID(), lightPropDiffuseLoc, lightProperties.diffuse.r, lightProperties.diffuse.g, lightProperties.diffuse.b );
		glProgramUniform3f( _shader->getProgramID(), lightPropSpecularLoc, lightProperties.specular.r, lightProperties.specular.g, lightProperties.specular.b );
		glProgramUniform3f( _shader->getProgramID(), lightPropPosLoc, lightSourcePos.x, lightSourcePos.y, lightSourcePos.z );
		

		glDrawArrays(GL_TRIANGLES, 0, _vertices.size() );
	}

	
	
	glBindVertexArray(0);
}
void Cube::setMaterial( const Material& material )
{
	_material = material;
}
const Material& Cube::getMaterial()
{
	return _material;
}