#ifndef Texture2D_H
#define Texture2D_H

#include "Ref.h"

_VESTART


class Texture2D : public Ref
{
	int _pixelsWidth;
	int _pixelsHeight;

	GLuint _textureID;


	Texture2D();

	bool init( const std::string& aTextPath );

	public:

		virtual ~Texture2D();

		static Texture2D* create( const std::string& aTextPath );

		GLuint getTextureID();

		int getPixelthWidth();
		int getPixelthHeight();
};

_VEEND


#endif