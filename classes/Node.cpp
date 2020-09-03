#include "Node.h"

#include "TimeScheduler.h"

namespace GLSandbox
{

	Node::Node()
		: _transform(1.0f)
		, _transformDirty( true )
		, _rotate( 0.0f, 0.0f, 0.0f )
		, _pos( 0.0f, 0.0f, 0.0f )
		, _scale( 1.0f, 1.0, 1.0f )
		, _originShift( 0.0f, 0.0f, 0.0f )
		, _visible( true )
	{
	}
	Node::~Node()
	{
		for( auto child : _children )
			child->release();

		unscheduleUpdate();
	}
	const glm::mat4& Node::getTransform() const
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
	bool Node::init()
	{
		return onInit();
	}
	void Node::drawTraversal( const Mat4& parentTransform )
	{
		auto transform = parentTransform * getTransform();

		for( auto child : _children )
		{
			if( child->getVisible() )
			{
				child->drawTraversal( transform );
			}
		}

		draw( transform );
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
	void Node::setVisbile( bool visible )
	{
		_visible = visible;
	}
	bool Node::getVisible() const
	{
		return _visible;
	}
	void Node::setName( const std::string& name )
	{
		_name = name;
	}
	const std::string& Node::getName() const
	{
		return _name;
	}
	void Node::setOriginShift( const Vec3& shift )
	{
		if ( _originShift != shift )
		{
			_originShift = shift;
			_transformDirty = true;
		}
	}
	const Vec3& Node::getOriginShift() const
	{
		return _originShift;
	}
	void Node::addChild( Node* child )
	{
		if( child )
		{
			if ( _children.end() == std::find( _children.begin(), _children.end(), child ) )
			{
				_children.push_back( child );
				child->retain();
			}
		}
	}
	void Node::removeChild( Node* child )
	{
		if( child )
		{
			auto findIt = std::find( _children.begin(), _children.end(), child );
			if ( findIt != _children.end() )
			{
				(*findIt)->release();
				_children.erase( findIt );
			}
		}
	}
	void Node::scheduleUpdate()
	{
		getTimeScheduler()->addUpdateFunc( std::bind(&Node::update, this, std::placeholders::_1  ), this );
	}
	void Node::unscheduleUpdate()
	{
		getTimeScheduler()->delUpdateFunc( this );
	}
	const std::vector<Node*>& Node::getChildren() const
	{
		return _children;
	}
	Node* Node::getChild( const std::string& childName ) const
	{
		auto findIt = _children.end();
	
		for( auto child : _children )
		{
			if ( child->_name == childName )
			{
				return child;
			}
		}

		return nullptr;
	}

}