#include "TimeScheduler.h"

_USEVE

TimeScheduler::TimeScheduler( WorkingScope* scope )
	: WorkingScopeProvider( scope )
{
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
void TimeScheduler::onMainTick( float deltaTime )
{
	for( auto funcPair : _updateFunctions )
	{
		funcPair.second( deltaTime );
	}
}