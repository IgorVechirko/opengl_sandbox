#ifndef Ref_H
#define Ref_H

#include "VECommon.h"

_VESTART


class Ref
{

	unsigned int _refCount;
	bool _autorelesed;

public:

	Ref();
	virtual ~Ref();

	void release();
	void retain();
	unsigned int getRefCount();

	void autorelease();
};

_VEEND

#endif