#ifndef Node_H
#define Node_H

#include "Ref.h"
#include "WorkingScopeProvider.h"
#include "WorkingScope.h"

#define CREATE_FUNC(__TYPE__)\
static __TYPE__* create()\
{\
__TYPE__* ret = new __TYPE__();\
\
if ( ret && ret->Node::init(nullptr) )\
{\
}\
else\
{\
delete ret;\
ret = nullptr;\
}\
return ret;\
}\
static __TYPE__* create(WorkingScope* scope)\
{\
__TYPE__* ret = new __TYPE__();\
\
if ( ret && ret->Node::init(scope) )\
{\
ret->autorelease(scope->getReleasePool());\
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
class Node
	: public Ref
	, public WorkingScopeProvider
{

	glm::mat4 _transform;
	bool _transformDirty;

protected:

	Vec3 _pos;
	Vec3 _rotate;
	Vec3 _scale;

	Vec3 _originShift;

	std::string _name;

	int _zOrder;

	bool _isChildrenSorted;
	std::vector<Node*> _children;

protected:

	const glm::mat4& getTransform();


	virtual bool onInit(){ return true;};

	virtual void update( float delatTime ){};

	virtual void visit( GLRender* render, const Mat4& parentTransform );
	virtual void draw( GLRender* render, const Mat4& transform ){};

	void sortChildren();

public:

	Node();
	virtual ~Node();

	CREATE_FUNC(Node);

	bool init(WorkingScope* scope);

	virtual void setPosition( const Vec3& pos );
	const Vec3& getPosition() const;

	virtual void setRotate( const Vec3& rotate );
	const Vec3& getRotate() const;

	virtual void setScale( const Vec3& scale );
	const Vec3& getScale() const;

	void setName( const std::string& name );
	const std::string& getName() const;

	void setZorder( int zOrder );
	int getZorder();

	void setOriginShift( const Vec3& shift );
	const Vec3& getOriginShift();

	void addChild( Node* child );
	void removeChild( Node* child );

	void scheduleUpdate();
	void unscheduleUpdate();

	const std::vector<Node*>& getChildren();
	Node* getChild( const std::string& childName );
	
	template<typename T> 
	T getChild( const std::string& childName )
	{
		return dynamic_cast<T>( getChild( childName ) );
	}
};

_VEEND

#endif