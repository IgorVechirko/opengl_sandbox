#include "Node.h"

#include "GLRender.h"

_USEVE

Node::Node()
	: _transMatrix(1.0f)
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
const glm::mat4& Node::getTransMatrix()
{
	if ( _transDirty )
	{
		_transDirty = false;

		_transMatrix = glm::mat4(1.0f);

		glm::mat4 actionMat(1.0f);
		actionMat = glm::scale( actionMat, glm::vec3(_scale.x,_scale.y,_scale.z) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.x), glm::vec3(1.0f, 0.0f, 0.0f) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.y), glm::vec3(0.0f, 1.0f, 0.0f) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate.z), glm::vec3(0.0f, 0.0f, 1.0f) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::translate(actionMat, glm::vec3(_pos.x, _pos.y, _pos.z) );
		_transMatrix *= actionMat;
	}

	return _transMatrix;
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