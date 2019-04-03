#ifndef ResourcesManager_H
#define ResourcesManager_H

#include "VECommon.h"

_VESTART


class ResourcesManager
{

	std::map<std::string,std::string> _resIDs;


	ResourcesManager();
	virtual ~ResourcesManager();

public:

	static ResourcesManager* getInstance();

	void parceResConfig( const std::string& aConfigPath );

	const std::string& getResPath( const std::string& aResID ) const;

};

#define RESOURCES ResourcesManager::getInstance()
#define RES_PATH( x ) ResourcesManager::getInstance->getResPath( x )

_VEEND


#endif