#ifndef AxisesOrigin_H
#define AxisesOrigin_H

#include "Node.h"


_VESTART


class AxisesOrigin : public Node
{
	typedef Node Parent;


protected:

	AxisesOrigin();

	virtual bool init() override;


public:

	virtual ~AxisesOrigin();

	CREATE_FUNC(AxisesOrigin);

};


_VEEND

#endif

