#ifndef Ref_H
#define Ref_H

#include "VECommon.h"

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
		unsigned int getRefCount();

		void autorelease( AutoReleasePool* pool );
	};

}

#endif