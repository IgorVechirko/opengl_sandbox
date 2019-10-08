#include "ResourcesManager.h"

#include "Director.h"

_USEVE


ResourcesManager::ResourcesManager()
{
}
ResourcesManager::~ResourcesManager()
{
}
void ResourcesManager::init()
{
	parseResConfig( "resdb/resources.json" );
}
void ResourcesManager::parseResConfig( const std::string& aConfigPath )
{
	std::string fileStr = FILE_UTILS->getStringFromFile( aConfigPath );

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
		return "";
	}
}