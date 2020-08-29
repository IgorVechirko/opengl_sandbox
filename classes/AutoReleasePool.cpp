#include "AutoReleasePool.h"

#include "Ref.h"

namespace GLSandbox
{

	AutoReleasePool::AutoReleasePool()
	{
	}
	AutoReleasePool::~AutoReleasePool()
	{
	}
	void AutoReleasePool::releaseRef( Ref* ref )
	{
		if ( ref && ref->getRefCount() == 0 )
		{
			auto findIt = std::find( _refs.begin(), _refs.end(), ref );
			if ( findIt != _refs.end() )
			{
				destoryObj( *findIt );
				_refs.erase( findIt );
			}
		}
	}
	void AutoReleasePool::addRef( Ref* newRef )
	{
		auto findIt = std::find( _refs.begin(), _refs.end(), newRef );
		if ( findIt == _refs.end() )
		{
			_refs.push_back( newRef );
		}
	}
	void AutoReleasePool::checkPool()
	{
		for ( auto refIt = _refs.begin(); refIt != _refs.end(); )
		{
			if ( (*refIt)->getRefCount() == 0 )
			{
				destoryObj(*refIt);
				refIt = _refs.erase( refIt );
			}
			else
			{
				refIt++;
			}
		}
	}

}