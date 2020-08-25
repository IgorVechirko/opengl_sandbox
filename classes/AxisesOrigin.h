#ifndef AxisesOrigin_H
#define AxisesOrigin_H

#include "Node.h"


_VESTART


class AxisesOrigin : public Node
{
	typedef Node Parent;


protected:

	virtual bool onInit() override;

public:

	AxisesOrigin();
	virtual ~AxisesOrigin();

};


_VEEND

#endif

