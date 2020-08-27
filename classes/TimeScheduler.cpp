#include "TimeScheduler.h"

#include <thread>

namespace GLSandbox
{

	TimeScheduler::TimeScheduler( WorkingScope* scope )
		: WorkingScopeProvider( scope )
	{
		_lastTickTime = std::chrono::steady_clock::now();
	}
	TimeScheduler::~TimeScheduler()
	{
	}
	void TimeScheduler::addUpdateFunc( updateFunc func, void* target )
	{
		if ( func && target )
		{
			auto findIt = _updateFunctions.find( target );
			if ( findIt == _updateFunctions.end() )
			{
				_updateFunctions[ target ] = func;
			}
		}
	}
	void TimeScheduler::delUpdateFunc( void* target )
	{
		if ( target )
		{
			auto findIt = _updateFunctions.find( target );
			if ( findIt != _updateFunctions.end() )
			{
				_updateFunctions.erase( findIt );
			}
		}
	}
	void TimeScheduler::doMainTick()
	{
		auto prevTickTime = _lastTickTime;
		_lastTickTime = std::chrono::steady_clock::now();
	
		auto secondsDuration = std::chrono::duration_cast<std::chrono::duration<float>>(_lastTickTime - prevTickTime);

		for( const auto& funcPair : _updateFunctions )
		{
			funcPair.second( secondsDuration.count() );
		}
	}
	void TimeScheduler::doWaitFrameEnd()
	{
		auto frameFinishTime = _lastTickTime + std::chrono::duration<int,std::ratio<1,60>>(1);
		std::this_thread::sleep_until( frameFinishTime );
	}

}