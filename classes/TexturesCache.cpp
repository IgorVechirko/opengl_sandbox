#include "TexturesCache.h"

#include "Texture2D.h"
#include "TimeScheduler.h"

namespace GLSandbox
{

	TexturesCache::TexturesCache()
	{
	}
	TexturesCache::~TexturesCache()
	{
		getTimeScheduler()->delUpdateFunc( this );

		for( auto& texturePair : _cachedTextures )
			texturePair.second->release();
	}
	void TexturesCache::init()
	{
		getTimeScheduler()->addUpdateFunc( std::bind( &TexturesCache::checkUnusedTextures, this, std::placeholders::_1 ), this );
	}
	void TexturesCache::checkUnusedTextures( float deltaTime )
	{
		for( auto textIt = _cachedTextures.begin(); textIt != _cachedTextures.end(); )
		{
			if( textIt->second->getRefCount() == 1 && !textIt->second->isAllwaysCached() )
			{
				textIt->second->release();
				textIt = _cachedTextures.erase( textIt );
			}
			else
				textIt++;
		}
	}
	Texture2D* TexturesCache::createTexture2D( const std::string& filePath )
	{
		Texture2D* result = nullptr;

		auto findIt = _cachedTextures.find( filePath );
		if ( findIt != _cachedTextures.end() )
		{
			result = findIt->second;
		}
		else
		{
			result = createRefWithInitializer<Texture2D>(&Texture2D::initWithFilePath, filePath );
			if ( result )
			{
				result->retain();
				_cachedTextures[ filePath ] = result;
			}
		}

		return result;
	}
	Texture2D* TexturesCache::getTexture2D( const std::string& filePath )
	{
		Texture2D* result = nullptr;

		auto findIt = _cachedTextures.find( filePath );
		if ( findIt != _cachedTextures.end() )
		{
			result = findIt->second;
		}

		return result;
	}
	const std::map<std::string, Texture2D*>& TexturesCache::getCachedTextures()
	{
		return _cachedTextures;
	}
	void TexturesCache::removeAlwaysCachedTexture()
	{
		for( auto textIt = _cachedTextures.begin(); textIt != _cachedTextures.end(); )
		{
			if ( textIt->second->isAllwaysCached() )
			{
				textIt->second->setAllwaysCached( false );

				if( textIt->second->getRefCount() == 1  )
				{
					textIt->second->release();
					textIt = _cachedTextures.erase( textIt );
				}
				else
					textIt++;
			}
		}
	}


}