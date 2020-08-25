#ifndef FileUtils_H
#define FileUtils_H

#include "WorkingScopeProvider.h"

_VESTART

class FileUtils : public WorkingScopeProvider
{


public:

	FileUtils( WorkingScope* scope );
	virtual ~FileUtils();

	void init();

	std::string getStringFromFile( const std::string& aPath );

};


#define FILES FileUtils::getInstance()

_VEEND



#endif
