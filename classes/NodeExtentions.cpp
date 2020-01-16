#include "NodeExtentions.h"

#include "ShaderProgram.h"

_USEVE


Size3Protocol::Size3Protocol()
	: _size( 0.0f )
{
}
Size3Protocol::~Size3Protocol()
{
}
void Size3Protocol::setSize3( const Size3& size )
{
	_size = size;
}
const Size3& Size3Protocol::getSize3()
{
	return _size;
}



ShaderProtocol::ShaderProtocol()
	: _shader( nullptr )
{
}
ShaderProtocol::~ShaderProtocol()
{
	setShaderProgram( nullptr );
}
void ShaderProtocol::setShaderProgram( ShaderProgram* program )
{
	if ( program != _shader )
	{
		if ( _shader )
			_shader->release();

		_shader = program;

		if ( _shader )
			_shader->retain();
	}
}
const ShaderProgram* ShaderProtocol::getShaderProgram()
{
	return _shader;
}