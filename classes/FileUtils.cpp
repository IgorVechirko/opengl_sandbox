#include "FileUtils.h"


_USEVE

FileUtils::FileUtils()
{
}
FileUtils::~FileUtils()
{
}
FileUtils* FileUtils::getInstance()
{
	static FileUtils instance;
	return &instance;
}
std::string FileUtils::getStringFromFile( const std::string& aPath )
{
	std::string result;

	FILE* openFile = fopen( aPath.c_str(), "r" );

	if ( openFile )
	{
		char nextSym;

		while ( ( nextSym = fgetc(openFile) ) != EOF )
		{
			result += nextSym;
		}

		fclose( openFile );
		openFile = nullptr;
	}

	return result;
}