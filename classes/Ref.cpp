#include "Ref.h"

#include "AutoReleasePool.h"


namespace GLSandbox
{

	Ref::Ref()
		: _refCount( 0 )
		, _pool( nullptr )
	{
	}

	Ref::~Ref()
	{
	}
	void Ref::release()
	{
		_ASSERT(_refCount > 0 ); 
		_refCount--;

		if ( _pool && _refCount == 0 )
		{
			_pool->releaseRef( this );
		}
	}
	void Ref::retain()
	{
		_refCount++;
	}
	unsigned int Ref::getRefCount() const
	{
		return _refCount;
	}
	void Ref::setupReleasePool( AutoReleasePool* pool )
	{
		if ( !_pool && pool)
		{
			_pool = pool;
			_pool->addRef( this );
		}
	}
}