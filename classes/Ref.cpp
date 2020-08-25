#include "Ref.h"

#include "AutoReleasePool.h"


_USEVE

Ref::Ref()
	: _refCount( 0 )
	, _autorelesed( false )
	, _pool( nullptr )
{
}

Ref::~Ref()
{
}
void Ref::release()
{
	_refCount--;

	if ( _pool && _autorelesed && _refCount == 1 )
	{
		_pool->releaseRef( this );
	}
}
void Ref::retain()
{
	_refCount++;
}
unsigned int Ref::getRefCount()
{
	return _refCount;
}
void Ref::autorelease( AutoReleasePool* pool )
{
	if ( !_autorelesed && pool)
	{
		_pool = pool;
		_autorelesed = true;
		_pool->addRef( this );
	}
}