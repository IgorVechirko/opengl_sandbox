#include "Ref.h"

#include "AutoRelesaePool.h"

_USEVE

Ref::Ref()
	: _refCount( 0 )
	, _autorelesed( false )
{
}

Ref::~Ref()
{
}
void Ref::release()
{
	_refCount--;

	if ( _autorelesed && _refCount == 1 )
	{
		AutoReleasePool::getInstance()->releaseRef( this );
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
void Ref::autorelease()
{
	if ( !_autorelesed )
	{
		AutoReleasePool::getInstance()->addRef( this );
	}
}