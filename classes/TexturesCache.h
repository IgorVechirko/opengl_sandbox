#ifndef TexturesCache_H
#define TexturesCache_H


#include "WorkingScopeProvider.h"


namespace GLSandbox
{
	class Texture2D;
	class TexturesCache : public WorkingScopeProvider
	{

		std::map<std::string, Texture2D*> _cachedTextures;



		void checkUnusedTextures( float deltaTime );


	public:

		TexturesCache();
		virtual ~TexturesCache();
		MAKE_UNCOPYABLE( TexturesCache );

		void init();

		Texture2D* createTexture2D( const std::string& filePath );
		Texture2D* getTexture2D( const std::string& filePath );

		const std::map<std::string, Texture2D*>& getCachedTextures();

		void removeAlwaysCachedTexture();

	};

}


#endif