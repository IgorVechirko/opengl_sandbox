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
		bool _autorelesed;

		AutoReleasePool* _pool;

	public:

		Ref();
		virtual ~Ref();

		void release();
		void retain();
		unsigned int getRefCount() const;

		void autorelease( AutoReleasePool* pool );
	};

}

#endif