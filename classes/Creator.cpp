#include "Creator.h"

namespace GLSandbox
{
	Creator::Creator()
		: _scope( nullptr )
	{
	}
	Creator::~Creator()
	{
	}
	void Creator::setScope( WorkingScope* scope )
	{
		_scope = scope;
	}
	WorkingScope* Creator::getScope()
	{
		return _scope;
	}
}
