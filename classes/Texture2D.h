#ifndef Texture2D_H
#define Texture2D_H

#include "Ref.h"

namespace GLSandbox
{

	class AutoReleasePool;
	class Texture2D : public Ref
	{
		int _width;
		int _height;

		GLuint _textureID;

		public:

			Texture2D();
			virtual ~Texture2D();

			bool initWithFilePath( const std::string& filePath );

			GLuint getTextureID();

			int getWidth();
			int getHeight();
	};

}


#endif