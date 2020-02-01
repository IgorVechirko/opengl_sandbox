#include "Node.h"

#include "Director.h"

_USEVE

Node::Node()
	: _transform(1.0f)
	, _transformDirty( true )
	, _rotate( 0.0f, 0.0f, 0.0f )
	, _pos( 0.0f, 0.0f, 0.0f )
	, _scale( 1.0f, 1.0, 1.0f )
{
}
Node::~Node()
{
	unscheduleUpdate();

	bool stop = true;
}
const glm::mat4& Node::getTransform()
{
	if ( _transformDirty )
	{
		_transformDirty = false;

		_transform = glm::mat4(1.0f);

		glm::mat4 actionMat(1.0f);
		actionMat = glm::translate(actionMat, _pos );
		_transform *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::scale( actionMat, glm::vec3(_scale.x,_scale.y,_scale.z) );
		_transform *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.x), glm::vec3(1.0f, 0.0f, 0.0f) );
		_transform *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.y), glm::vec3(0.0f, 1.0f, 0.0f) );
		_transform *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.z), glm::vec3(0.0f, 0.0f, 1.0f) );
		_transform *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::translate(actionMat, _originShift );
		_transform *= actionMat;
	}

	return _transform;
}
void Node::visit( GLRender* render, const Mat4& parentTransform )
{
	auto transform = parentTransform * getTransform();

	if( !_isChildrenSorted )
	{
		sortChildren();
	}

	int i = 0;
	for( ; i < _children.size(); i++ )
	{
		if ( _children[i]->_zOrder < 0 )
		{
			_children[i]->visit( render, transform );
		}
		else
		{
			break;
		}
	}

	draw( render, transform );

	for( ; i < _children.size(); i ++)
	{
		_children[i]->visit( render, transform );
	}
}
void Node::sortChildren()
{
	if ( !_isChildrenSorted )
	{
		std::sort( _children.begin(), _children.end(), [](Node* a, Node* b)-> bool {
			return a->_zOrder > b->_zOrder;
		});

		_isChildrenSorted = true;
	}
}
void Node::setPosition( const Vec3& pos )
{
	if ( pos != _pos )
	{
		_pos = pos;
		_transformDirty = true;;
	}
}
const Vec3& Node::getPosition() const
{
	return _pos;
}
void Node::setRotate( const Vec3& rotate )
{
	if ( rotate != _rotate )
	{
		_rotate = rotate;
		_transformDirty = true;;
	}
}
const Vec3& Node::getRotate() const
{
	return _rotate;
}
void Node::setScale( const Vec3& scale )
{
	if ( scale != _scale )
	{
		_scale = scale;
		_transformDirty = true;;
	}
}
const Vec3& Node::getScale() const
{
	return _scale;
}
void Node::setName( const std::string& name )
{
	_name = name;
}
const std::string& Node::getName() const
{
	return _name;
}
void Node::setZorder( int zOrder )
{
	_zOrder = zOrder;
}
int Node::getZorder()
{
	return _zOrder;
}
void Node::setOriginShift( const Vec3& shift )
{
	if ( _originShift != shift )
	{
		_originShift = shift;
		_transformDirty = true;
	}
}
const Vec3& Node::getOriginShift()
{
	return _originShift;
}
void Node::addChild( Node* child )
{
	if ( _children.end() == std::find( _children.begin(), _children.end(), child ) )
	{
		_isChildrenSorted = false;
		_children.push_back( child );
	}
}
void Node::removeChild( Node* child )
{
	auto findIt = std::find( _children.begin(), _children.end(), child );
	if ( findIt != _children.end() )
	{
		_children.erase( findIt );
	}
}
void Node::scheduleUpdate()
{
	SCHEDULER->addUpdateFunc( std::bind(&Node::update, this, std::placeholders::_1  ), this );
}
void Node::unscheduleUpdate()
{
	SCHEDULER->delUpdateFunc( this );
}
const std::vector<Node*>& Node::getChildren()
{
	return _children;
}
Node* Node::getChild( const std::string& childName )
{
	auto findIt = _children.end();
	
	for( auto& child : _children )
	{
		if ( child->_name == childName )
		{
			return child;
		}
	}

	return nullptr;
}
template<typename T> T Node::getChild( const std::string& childName )
{
	return dynamic_cast<T>( getChild( childName ) );
}