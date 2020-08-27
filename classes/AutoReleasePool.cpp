#include "AutoReleasePool.h"

#include "Ref.h"

namespace GLSandbox
{

	AutoReleasePool::AutoReleasePool( WorkingScope* scope )
		: WorkingScopeProvider( scope )
	{
	}
	AutoReleasePool::~AutoReleasePool()
	{
	}
	void AutoReleasePool::releaseRef( Ref* ref )
	{
		if ( ref && ref->getRefCount() == 1 )
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
	void AutoReleasePool::checkPool()
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

}