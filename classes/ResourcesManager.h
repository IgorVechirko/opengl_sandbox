#ifndef ResourcesManager_H
#define ResourcesManager_H

#include "WorkingScopeProvider.h"

namespace GLSandbox
{


	class ResourcesManager : public WorkingScopeProvider
	{

		std::map<std::string,std::string> _resIDs;

	public:

		ResourcesManager();
		virtual ~ResourcesManager();


		void init();

		void parseResConfig( const std::string& aConfigPath );

		const std::string& getResPath( const std::string& aResID ) const;

		std::string getResStr( const std::string& resID );

	};

}


#endif