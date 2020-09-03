#ifndef Texture2D_H
#define Texture2D_H

#include "Ref.h"

namespace GLSandbox
{
	class TexturesCache;
	class Texture2D : public Ref
	{
		friend TexturesCache;

		int _width;
		int _height;

		GLuint _textureID;

		bool _allwaysCached;

		public:

			Texture2D();
			virtual ~Texture2D();
			MAKE_UNCOPYABLE(Texture2D);

			bool initWithFilePath( const std::string& filePath );

			void useTexture( unsigned int samplerIndx = 0 );

			int getWidth() const;
			int getHeight() const;

			void setAllwaysCached( bool allwaysCached );
			bool isAllwaysCached() const;
	};

}


#endif