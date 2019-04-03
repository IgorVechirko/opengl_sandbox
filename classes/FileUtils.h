#ifndef FileUtils_H
#define FileUtils_H

#include "VECommon.h"

_VESTART

class FileUtils
{

	FileUtils();
	virtual ~FileUtils();

	public:

		static FileUtils* getInstance();

		std::string getStringFromFile( const std::string& aPath );

};


#define FILES FileUtils::getInstance()

_VEEND



#endif
