#include "Node.h"

_USEVE

Node::Node()
	: _transMatrix(1.0f)
	, _transDirty( true )
	, _rotate( 0.0f )
	, _pos( 0.0f, 0.0f )
	, _scale( 1.0f, 1.0 )
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
		actionMat = glm::scale( actionMat, glm::vec3(_scale.x,_scale.y,1.0f) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::rotate( actionMat, glm::radians(_rotate), glm::vec3(0.0f, 0.0f, 1.0f) );
		_transMatrix *= actionMat;

		actionMat = glm::mat4(1.0f);
		actionMat = glm::translate(actionMat, glm::vec3(_pos.x, _pos.y, 0.0f) );
		_transMatrix *= actionMat;
	}

	return _transMatrix;
}
void Node::setPosition( const Vec& pos )
{
	if ( pos != _pos )
	{
		_pos = pos;
		_transDirty;
	}
}
const Vec& Node::getPosition() const
{
	return _pos;
}
void Node::setRotate( const float angle )
{
	if ( angle != _rotate )
	{
		_rotate = angle;
		_transDirty;
	}
}
float Node::getRotate() const
{
	return _rotate;
}
void Node::setScale( const Vec& scale )
{
	if ( scale != _scale )
	{
		_scale = scale;
		_transDirty;
	}
}
const Vec& Node::getScale() const
{
	return _scale;
}