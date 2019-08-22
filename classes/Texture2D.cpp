#include "Texture2D.h"

#include "SOIL.h"

_USEVE

Texture2D::Texture2D()
	: _textureID( 0 )
	, _pixelsWidth( 0 )
	, _pixelsHeight( 0 )
{
}
Texture2D::~Texture2D()
{
	glDeleteTextures( 1, &_textureID );
	_textureID = 0;
}
Texture2D* Texture2D::create(const std::string& aTextPath)
{
	Texture2D* ret = new Texture2D();

	if ( ret && ret->init( aTextPath ) )
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
bool Texture2D::init( const std::string& aTextPath )
{
	glGenTextures( 1, &_textureID );
	glBindTexture( GL_TEXTURE_2D, _textureID );

	unsigned char* image = SOIL_load_image( aTextPath.c_str(), &_pixelsWidth, &_pixelsHeight, 0, SOIL_LOAD_RGB );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, _pixelsWidth, _pixelsHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image );
	glGenerateMipmap( GL_TEXTURE_2D );

	SOIL_free_image_data(image);
	glBindTexture( GL_TEXTURE_2D, 0 );

	return true;
}
GLuint Texture2D::getTextureID()
{
	return _textureID;
}
int Texture2D::getPixelthWidth()
{
	return _pixelsWidth;
}
int Texture2D::getPixelthHeight()
{
	return _pixelsHeight;
}