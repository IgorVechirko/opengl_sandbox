#include "Sprite.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "ResourcesManager.h"
#include "GLRender.h"

_USEVE

Sprite::Sprite()
	: _texture( nullptr )
	, _shader( nullptr )
	, _vbo( 0 )
	, _vao( 0 )
	, _ebo( 0 )
{
}
Sprite::~Sprite()
{
}
Sprite* Sprite::create( const std::string& filePath )
{
	Sprite* ret = new Sprite();

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
void Sprite::updateVertices( const Size& size )
{
}
bool Sprite::init( const std::string& filePath )
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
void Sprite::setShaderProgram( ShaderProgram* program )
{
	if ( program )
	{
		if ( _shader )
			_shader->release();

		_shader = program;
		_shader->retain();
	}
}
void Sprite::setTexture( Texture2D* texture )
{
	if ( texture )
	{
		if ( _texture )
			_texture->release();

		_texture = texture;
		_texture->retain();

		Size textSize( _texture->getPixelthWidth(), _texture->getPixelthHeight() );


		_vertices = {	0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
						 textSize.x, 0.0f, 0.0f,  1.0f, 0.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,
						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 0.0f,

						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,
						0.0f,  textSize.x,  textSize.x,  0.0f, 1.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,

						0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f,
						0.0f,  textSize.x, 0.0f,  1.0f, 1.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,
						0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f,

						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,
						 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,
						 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,
						 textSize.x, 0.0f,  textSize.x,  0.0f, 0.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,

						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
						 textSize.x, 0.0f, 0.0f,  1.0f, 1.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,
						 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,
						0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,
						0.0f, 0.0f, 0.0f,  0.0f, 1.0f,

						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,
						 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,
						 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,
						0.0f,  textSize.x,  textSize.x,  0.0f, 0.0f,
						0.0f,  textSize.x, 0.0f,  0.0f, 1.0f };

		_indices = { 0, 1, 2,
					 1, 2, 3 };

		setShaderProgram( ShaderProgram::create( RES_PATH("SPRITE_VERTEX"), RES_PATH("SPRITE_FRAGMENT") ) );

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

		//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(6*sizeof(GLfloat)));
		//glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}
void Sprite::draw( const Mat4& projection, const Mat4& view )
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

		glProgramUniformMatrix4fv( _shader->getProgramID(), transModelLoc, 1, GL_FALSE, glm::value_ptr( getTransMatrix() ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transViewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
		glProgramUniformMatrix4fv( _shader->getProgramID(), transProjLoc, 1, GL_FALSE, glm::value_ptr( projection ) );

		glDrawArrays(GL_TRIANGLES, 0, _vertices.size() );
	}

	
	
	glBindVertexArray(0);
}