#include "Node.h"

#include "GLRender.h"

_USEVE

Node::Node()
	: _transform(1.0f)
	, _transDirty( true )
	, _rotate( 0.0f, 0.0f, 0.0f )
	, _pos( 0.0f, 0.0f, 0.0f )
	, _scale( 1.0f, 1.0, 1.0f )
{
}
Node::~Node()
{
	bool stop = true;
}
const glm::mat4& Node::getTransform()
{
	if ( _transDirty )
	{
		_transDirty = false;

		_transform = glm::mat4(1.0f);

		glm::mat4 actionMat(1.0f);
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
		actionMat = glm::translate(actionMat, glm::vec3(_pos.x, _pos.y, _pos.z) );
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
			return a->_zOrder >= b->_zOrder;
		});

		_isChildrenSorted = true;
	}
}
void Node::setPosition( const Vec3& pos )
{
	if ( pos != _pos )
	{
		_pos = pos;
		_transDirty;
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
		_transDirty;
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
		_transDirty;
	}
}
const Vec3& Node::getScale() const
{
	return _scale;
}
void Node::setSize( const Size& size )
{
	_size = size;
}
const Size& Node::getSize() const
{
	return _size;
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