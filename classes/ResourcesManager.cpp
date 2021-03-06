#include "ResourcesManager.h"

#include "FileUtils.h"



namespace GLSandbox
{


	ResourcesManager::ResourcesManager()
	{
	}
	ResourcesManager::~ResourcesManager()
	{
	}
	void ResourcesManager::parseResConfig( const std::string& aConfigPath )
	{
		std::string fileStr = getFileUtils()->getStringFromFile( aConfigPath );

		rapidjson::Document jsonDoc;
		jsonDoc.Parse<0>( fileStr.c_str() );

		if ( !jsonDoc.HasParseError() && jsonDoc.IsObject() )
		{
			for ( auto resInfoIt = jsonDoc.MemberBegin(); resInfoIt != jsonDoc.MemberEnd(); resInfoIt++ )
			{
				if ( resInfoIt->value.IsString() )
				{
					_resIDs[ resInfoIt->name.GetString() ] = resInfoIt->value.GetString();
				}
			}
		}
	}
	const std::string& ResourcesManager::getResPath( const std::string& aResID ) const
	{
		auto findPathIt = _resIDs.find( aResID );
		if ( findPathIt != _resIDs.end() )
		{
			return findPathIt->second;
		}
		else
		{
			static std::string emptyResult( "" );
			return emptyResult;
		}
	}
	std::string ResourcesManager::getResStr( const std::string& resID )
	{
		const auto& resPath = getResPath( resID );
		return getFileUtils()->getStringFromFile( resPath );

	}

}