#ifndef AutoReleasePool_H
#define AutoReleasePool_H


#include "VECommon.h"

_VESTART

class Ref;
class AutoReleasePool
{

	std::vector<Ref*> _refs;


public:

	AutoReleasePool();
	virtual ~AutoReleasePool();

	void releaseRef( Ref* ref );
	void addRef( Ref* newRef );

	void checkPool();
};

_VEEND

#endif