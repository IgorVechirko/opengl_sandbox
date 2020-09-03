#ifndef Ref_H
#define Ref_H

#include "Common.h"

namespace GLSandbox
{
	class AutoReleasePool;
	class Ref
	{
		TEST_FRIEND

		unsigned int _refCount;

		AutoReleasePool* _pool;

	public:

		Ref();
		virtual ~Ref();
		MAKE_UNCOPYABLE(Ref);

		void release();
		void retain();
		unsigned int getRefCount() const;

		void setupReleasePool( AutoReleasePool* pool );
	};

}

#endif