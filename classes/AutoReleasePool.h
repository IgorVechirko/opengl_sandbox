#ifndef AutoReleasePool_H
#define AutoReleasePool_H


#include "WorkingScopeProvider.h"

_VESTART

class Ref;
class AutoReleasePool : public WorkingScopeProvider
{

	std::vector<Ref*> _refs;


public:

	AutoReleasePool( WorkingScope* scope );
	virtual ~AutoReleasePool();

	void releaseRef( Ref* ref );
	void addRef( Ref* newRef );

	void checkPool();
};

_VEEND

#endif