#ifndef Node_H
#define Node_H

#include "Ref.h"

#define CREATE_FUNC(__TYPE__) static __TYPE__* create()\
{\
__TYPE__* ret = new __TYPE__();\
\
if ( ret && ret->init() )\
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

	Vec3 _pos;
	Vec3 _rotate;
	Vec3 _scale;

	glm::mat4 _transMatrix;
	bool _transDirty;

	std::string _name;

	bool _isChildrenSorted;
	std::vector<Node*> _children;


protected:

	Node();

	virtual bool init(){return true;};

	const glm::mat4& getTransMatrix();

public:

	virtual ~Node();

	CREATE_FUNC(Node);

	virtual void draw( const Mat4& projection, const Mat4& view ){};

	void setPosition( const Vec3& pos );
	const Vec3& getPosition() const;

	void setRotate( const Vec3& rotate );
	const Vec3& getRotate() const;

	void setScale( const Vec3& scale );
	const Vec3& getScale() const;

	void setName( const std::string& name );
	const std::string& getName() const;

	void addChild( Node* child );
	void removeChild( Node* child );
	Node* getChild( const std::string& childName );

	
};

_VEEND

#endif