#ifndef DrawTypes_H
#define DrawTypes_H

#include "Common.h"

namespace GLSandbox
{
	enum class StandartShaderType
	{
		POS_UCOLOR,
		POS_NORMAL_LIGHT_PROP,
		POS_UV_TEXTURE,
		POS_UV_NORMAL_LIGHT_PORP,
		NO_MVP_POS_UV_TEXTURE,
		NO_MODEL_CUBE_SAMPLER,
		POS_NORMAL_SKYBOX_REFLECTION,
		POS_NORMAL_SKYBOX_REFRACTION
	};

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

	struct PosUVNormalVertex
	{
		Vec3 pos;
		Vec2 uv;
		Vec3 normal;
	};


}


#endif