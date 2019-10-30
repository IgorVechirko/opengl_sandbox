#ifndef TimeScheduler_H
#define TimeScheduler_H

#include "VECommon.h"

_VESTART

typedef std::function<void(float)> updateFunc;

class TimeScheduler
{

	std::map<void*,updateFunc> _updateFunctions;


public:

	TimeScheduler();
	virtual ~TimeScheduler();

	void addUpdateFunc( updateFunc func, void* target );
	void delUpdateFunc( void* target );

	void onMainTick( float deltaTime );

};


_VEEND


#endif