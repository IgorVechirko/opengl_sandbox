#ifndef NodeExtentions_H
#define NodeExtentions_H

#include "VECommon.h"


_VESTART

class ShaderProgram;
class Size3Protocol
{

protected:

	Size3 _size;
	

protected:

	Size3Protocol();

public:

	virtual ~Size3Protocol();

	virtual void setSize3( const Size3& size );
	const Size3& getSize3();
};

class ShaderProtocol
{

protected:

	ShaderProtocol();

	ShaderProgram* _shader;

public:

	virtual ~ShaderProtocol();

	virtual void setShaderProgram( ShaderProgram* program );
	const ShaderProgram* getShaderProgram();

};


_VEEND


#endif
