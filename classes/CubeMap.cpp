#include "CubeMap.h"

namespace GLSandbox
{

	CubeMap::CubeMap()
	{
	}
	CubeMap::~CubeMap()
	{
		glDeleteTextures( 1, &_textureID );
		_textureID = 0;
	}
	bool CubeMap::initWithPlanesPaths( const std::array<std::string,6>& planesPaths )
	{
		glGenTextures(1, &_textureID);
		glBindTexture( GL_TEXTURE_CUBE_MAP, _textureID );

		for( int planeIndx = 0; planeIndx < planesPaths.size(); planeIndx++ )
		{
			int chanels = 0;
			int width = 0;
			int height = 0;

			unsigned char* image = SOIL_load_image( planesPaths[planeIndx].c_str(), &width, &height, &chanels, SOIL_LOAD_AUTO );

			if ( !image )
			{
				Console::log( "can't load texture ", planesPaths[planeIndx] );

				glDeleteTextures( 1, &_textureID );
				_textureID = 0;

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

			glTexImage2D( GL_TEXTURE_CUBE_MAP_POSITIVE_X + planeIndx, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, image );

			SOIL_free_image_data(image);
		}

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		return true;
	}
	void CubeMap::useCubeMap( int samplerIndx )
	{
		glActiveTexture( GL_TEXTURE0 + samplerIndx );
		glBindTexture( GL_TEXTURE_CUBE_MAP, _textureID );
	}

}