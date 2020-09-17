#ifndef AutoReleasePool_H
#define AutoReleasePool_H


#include "WorkingScopeProvider.h"

namespace GLSandbox
{
	class Ref;
	class AutoReleasePool : public WorkingScopeProvider
	{

		std::list<Ref*> _refs;


	public:

		AutoReleasePool();
		virtual ~AutoReleasePool();
		MAKE_UNCOPYABLE(AutoReleasePool);

		void releaseRef( Ref* ref );
		void addRef( Ref* newRef );

		void checkPool();
	};

}

#endif