#ifndef Texture2D_H
#define Texture2D_H

#include "VECommon.h"


class Texture2D
{
	GLuint _textureID;


	public:

		Texture2D() = delete;
		Texture2D( const std::string& aTextPath );
		virtual ~Texture2D();

		GLuint getTextureID();
};



#endif