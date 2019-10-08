#include "Ref.h"

#include "Director.h"

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
		RELEASE_POOL->releaseRef( this );
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
		_autorelesed = true;
		RELEASE_POOL->addRef( this );
	}
}