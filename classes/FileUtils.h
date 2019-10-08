#ifndef FileUtils_H
#define FileUtils_H

#include "VECommon.h"

_VESTART

class FileUtils
{


public:

	FileUtils();
	virtual ~FileUtils();

	void init();

	std::string getStringFromFile( const std::string& aPath );

};


#define FILES FileUtils::getInstance()

_VEEND



#endif
