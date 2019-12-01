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


class GLRender;
class Node : public Ref
{
	Vec3 _pos;
	Vec3 _rotate;
	Vec3 _scale;
	Size _size;

	glm::mat4 _transform;
	bool _transDirty;

protected:

	std::string _name;

	int _zOrder;

	bool _isChildrenSorted;
	std::vector<Node*> _children;

protected:


	Node();

	const glm::mat4& getTransform();


	virtual bool init(){return true;};

	virtual void update( float delatTime ){};

	virtual void visit( GLRender* render, const Mat4& parentTransform );
	virtual void draw( GLRender* render, const Mat4& transform ){};

	void sortChildren();

public:

	virtual ~Node();

	CREATE_FUNC(Node);

	void setPosition( const Vec3& pos );
	const Vec3& getPosition() const;

	void setRotate( const Vec3& rotate );
	const Vec3& getRotate() const;

	void setScale( const Vec3& scale );
	const Vec3& getScale() const;

	virtual void setSize( const Size& size );
	const Size& getSize() const;

	void setName( const std::string& name );
	const std::string& getName() const;

	void setZorder( int zOrder );
	int getZorder();

	void addChild( Node* child );
	void removeChild( Node* child );

	void scheduleUpdate();
	void unscheduleUpdate();

	const std::vector<Node*>& getChildren();
	Node* getChild( const std::string& childName );
	template<typename T> T getChild( const std::string& childName );
};

_VEEND

#endif