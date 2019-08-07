#include "AutoRelesaePool.h"

#include "Ref.h"

_USEVE

AutoReleasePool::AutoReleasePool()
{
}
AutoReleasePool::~AutoReleasePool()
{
}
AutoReleasePool* AutoReleasePool::getInstance()
{
	static AutoReleasePool instance;
	return &instance;
}
void AutoReleasePool::releaseRef( Ref* ref )
{
	if ( ref->getRefCount() == 1 )
	{
		auto findIt = std::find( _refs.begin(), _refs.end(), ref );
		if ( findIt != _refs.end() )
		{
			_refs.erase( findIt );
			delete ref;
		}
	}
}
void AutoReleasePool::addRef( Ref* newRef )
{
	auto findIt = std::find( _refs.begin(), _refs.end(), newRef );
	if ( findIt == _refs.end() )
	{
		newRef->retain();
		_refs.push_back( newRef );
	}
}
void AutoReleasePool::checkAutorelease()
{
	for ( auto refIt = _refs.begin(); refIt != _refs.end(); )
	{
		if ( (*refIt)->getRefCount() == 1 )
		{
			refIt = _refs.erase( refIt );
		}
		else
		{
			refIt++;
		}
	}
}