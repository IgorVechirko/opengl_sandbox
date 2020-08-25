#ifndef TimeScheduler_H
#define TimeScheduler_H

#include "WorkingScopeProvider.h"

_VESTART

typedef std::function<void(float)> updateFunc;

class TimeScheduler : public WorkingScopeProvider
{

	std::map<void*,updateFunc> _updateFunctions;


public:

	TimeScheduler( WorkingScope* scope );
	virtual ~TimeScheduler();

	void addUpdateFunc( updateFunc func, void* target );
	void delUpdateFunc( void* target );

	void onMainTick( float deltaTime );

};


_VEEND


#endif