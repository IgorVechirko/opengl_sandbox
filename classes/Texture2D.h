#ifndef Texture2D_H
#define Texture2D_H

#include "Ref.h"

namespace GLSandbox
{

	class Texture2D : public Ref
	{
		int _width;
		int _height;

		GLuint _textureID;

		public:

			Texture2D();
			virtual ~Texture2D();
			MAKE_UNCOPYABLE(Texture2D);

			bool initWithFilePath( const std::string& filePath );

			void useTexture( unsigned int samplerIndx = 0 );

			int getWidth() const;
			int getHeight() const;
	};

}


#endif