#ifndef DrawTypes_H
#define DrawTypes_H

#include "Common.h"

namespace GLSandbox
{

	struct PosVertex
	{
		Vec3 pos;
	};

	struct PosNormalVertex
	{
		Vec3 pos;
		Vec3 normal;
	};

	struct PosUVVertex
	{
		Vec3 pos;
		Vec2 uv;
	};


}


#endif