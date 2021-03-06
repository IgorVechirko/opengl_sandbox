#include "FileUtils.h"


namespace GLSandbox
{

	FileUtils::FileUtils()
	{
	}
	FileUtils::~FileUtils()
	{
	}
	void FileUtils::init()
	{
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

}