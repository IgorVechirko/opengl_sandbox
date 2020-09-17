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
				auto obj = (*findIt);
				_refs.erase( findIt );
				destoryObj( obj );
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
				auto obj = (*refIt);
				refIt = _refs.erase( refIt );
				destoryObj( obj );
			}
			else
			{
				refIt++;
			}
		}
	}

}