#ifndef ResourcesManager_H
#define ResourcesManager_H

#include "VECommon.h"

_VESTART


class ResourcesManager
{

	std::map<std::string,std::string> _resIDs;

public:

	ResourcesManager();
	virtual ~ResourcesManager();


	void init();

	void parseResConfig( const std::string& aConfigPath );

	const std::string& getResPath( const std::string& aResID ) const;

};

_VEEND


#endif