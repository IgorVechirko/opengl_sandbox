#include "Texture2D.h"

#include "SOIL.h"

_USEVE

Texture2D::Texture2D( const std::string& aTextPath )
	: _textureID( 0 )
{
	glGenTextures( 1, &_textureID );
	glBindTexture( GL_TEXTURE_2D, _textureID );

	int width, height;
	unsigned char* image = SOIL_load_image( aTextPath.c_str(), &width, &height, 0, SOIL_LOAD_RGB );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image );
	glGenerateMipmap( GL_TEXTURE_2D );

	SOIL_free_image_data(image);
	glBindTexture( GL_TEXTURE_2D, 0 );
}
Texture2D::~Texture2D()
{
	glDeleteTextures( 1, &_textureID );
	_textureID = 0;
}
GLuint Texture2D::getTextureID()
{
	return _textureID;
}