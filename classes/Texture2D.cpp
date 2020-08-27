#include "Texture2D.h"


namespace GLSandbox
{

	Texture2D::Texture2D()
		: _textureID( 0 )
		, _width( 0 )
		, _height( 0 )
	{
	}
	Texture2D::~Texture2D()
	{
		glDeleteTextures( 1, &_textureID );
		_textureID = 0;
	}
	bool Texture2D::initWithFilePath( const std::string& filePath )
	{
		glGenTextures( 1, &_textureID );
		glBindTexture( GL_TEXTURE_2D, _textureID );

		unsigned char* image = SOIL_load_image( filePath.c_str(), &_width, &_height, 0, SOIL_LOAD_RGB );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, image );
		glGenerateMipmap( GL_TEXTURE_2D );

		SOIL_free_image_data(image);
		glBindTexture( GL_TEXTURE_2D, 0 );

		return true;
	}
	GLuint Texture2D::getTextureID()
	{
		return _textureID;
	}
	int Texture2D::getWidth()
	{
		return _width;
	}
	int Texture2D::getHeight()
	{
		return _height;
	}

}