#ifndef TimeScheduler_H
#define TimeScheduler_H

#include "WorkingScopeProvider.h"

#include <chrono>

namespace GLSandbox
{

	typedef std::function<void(float)> updateFunc;

	class TimeScheduler : public WorkingScopeProvider
	{
		TEST_FRIEND

		std::chrono::time_point<std::chrono::steady_clock > _lastTickTime;

		std::map<void*,updateFunc> _updateFunctions;


	public:

		TimeScheduler( WorkingScope* scope );
		virtual ~TimeScheduler();
		MAKE_UNCOPYABLE(TimeScheduler);

		void addUpdateFunc( updateFunc func, void* target );
		void delUpdateFunc( void* target );

		void doMainTick();
		void doWaitFrameEnd();

	};


}


#endif