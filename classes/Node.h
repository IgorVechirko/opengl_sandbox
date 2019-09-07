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

	Vec _pos;
	float _rotate;
	Vec _scale;

	glm::mat4 _transMatrix;
	bool _transDirty;


protected:

	Node();

	const glm::mat4& getTransMatrix();

public:

	virtual ~Node();

	CREATE_FUNC(Node);

	virtual void draw(){};

	void setPosition( const Vec& pos );
	const Vec& getPosition() const;

	void setRotate( float angle );
	float getRotate() const;

	void setScale( const Vec& scale );
	const Vec& getScale() const;

	
};

_VEEND

#endif