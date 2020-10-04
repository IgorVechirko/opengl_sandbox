#include "Texture2D.h"


namespace GLSandbox
{

	Texture2D::Texture2D()
		: _textureID( 0 )
		, _width( 0 )
		, _height( 0 )
		, _allwaysCached( false )
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

		int chanels = 0;
		unsigned char* image = SOIL_load_image( filePath.c_str(), &_width, &_height, &chanels, SOIL_LOAD_AUTO );

		if ( !image )
		{
			return false;
		}

		GLenum format;
		switch(chanels)
		{
		case 1:
            format = GL_RED;
			break;
		case 3:
            format = GL_RGB;
			break;
		case 4:
            format = GL_RGBA;
			break;
		}

		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, format, GL_UNSIGNED_BYTE, image );
		glGenerateMipmap( GL_TEXTURE_2D );

		SOIL_free_image_data(image);
		glBindTexture( GL_TEXTURE_2D, 0 );

		return true;
	}
	void Texture2D::useTexture( unsigned int samplerIndx )
	{
		glActiveTexture( GL_TEXTURE0 + samplerIndx );
		glBindTexture( GL_TEXTURE_2D, _textureID );
	}
	int Texture2D::getWidth() const
	{
		return _width;
	}
	int Texture2D::getHeight() const
	{
		return _height;
	}
	void Texture2D::setAllwaysCached( bool allwaysCached )
	{
		_allwaysCached = allwaysCached;
	}
	bool Texture2D::isAllwaysCached() const
	{
		return _allwaysCached;
	}
}