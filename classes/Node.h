#ifndef Node_H
#define Node_H

#include "Ref.h"

#define CREATE_FUNC(__TYPE__) static __TYPE__* create()\
{\
__TYPE__* ret = new __TYPE__();\
\
if ( ret )\
{\
ret->autorelease();\
}\
else\
{\
delete ret;\
ret = nullptr;\
}\
return ret;\
}\


_VESTART


class Node : public Ref
{

	Node();

protected:

public:

	virtual ~Node();

	CREATE_FUNC(Node);

	virtual void draw(){};
};

_VEEND

#endif