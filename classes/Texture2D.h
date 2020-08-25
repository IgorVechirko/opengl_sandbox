#ifndef Texture2D_H
#define Texture2D_H

#include "Ref.h"

_VESTART

class AutoReleasePool;
class Texture2D : public Ref
{
	int _width;
	int _height;

	GLuint _textureID;


	Texture2D();

	bool init( const std::string& aTextPath );

	public:

		virtual ~Texture2D();

		static Texture2D* create( AutoReleasePool* pool, const std::string& aTextPath );

		GLuint getTextureID();

		int getWidth();
		int getHeight();
};

_VEEND


#endif