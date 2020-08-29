#include "Allocator.h"

namespace GLSandbox
{
	Allocator::Allocator()
		: _start( 0 )
		, _size( 0 )
		, _usedMemory( 0 )
		, _allocationsCount( 0 )
	{
	}
	Allocator::~Allocator()
	{
		_ASSERT( _allocationsCount == 0, "ATENTION!!! memory leack" );
	}
	void* Allocator::allocate( size_t size )
	{
		auto ptr = new char[size];
		_allocationsCount++;
		return static_cast<void*>(ptr);
	}
	void Allocator::deallocate( void* ptr )
	{
		_allocationsCount--;
		delete[] ptr;
	}
}