#ifndef AutoReleasePool_H
#define AutoReleasePool_H


#include "VECommon.h"

_VESTART

class Ref;
class AutoReleasePool
{

	std::vector<Ref*> _refs;


	AutoReleasePool();

public:

	virtual ~AutoReleasePool();

	static AutoReleasePool* getInstance();

	void releaseRef( Ref* ref );
	void addRef( Ref* newRef );
	void checkAutorelease();
};

_VEEND

#endif