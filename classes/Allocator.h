#ifndef Allocator_H
#define Allocator_H

#include "Common.h"
#include <cstdint>


namespace GLSandbox
{

	class Allocator
	{
		uintptr_t _start;
		size_t _size;
		size_t _usedMemory;

		size_t _allocationsCount;

	public:

		Allocator();
		virtual ~Allocator();
		MAKE_UNCOPYABLE(Allocator);

		void* allocate( size_t size );
		void deallocate( void* ptr );

	};
}


#endif