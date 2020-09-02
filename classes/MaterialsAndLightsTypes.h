#ifndef MaterialsAndLightsTypes_H
#define MaterialsAndLightsTypes_H

#include "Common.h"

namespace GLSandbox
{

	struct Material 
	{
		Vec3 ambient;
		Vec3 diffuse;
		Vec3 specular;
		float shininess;

		Material()
			: shininess( 1.0f )
			, ambient( 0.0f )
			, diffuse( 0.0f )
			, specular( 0.0f )
		{};
	};

	struct LightProperties
	{
		Vec3 ambient;
		Vec3 diffuse;
		Vec3 specular;

		LightProperties()
			: ambient( 0.0f, 0.0f, 0.0f )
			, diffuse( 0.0f, 0.0f, 0.0f )
			, specular( 0.0f, 0.0f, 0.0f )
		{
		};
	};

	struct LightAttenuationCoefs
	{
		float constant;
		float linear;
		float quadratic;

		LightAttenuationCoefs()
			: constant( 1.0f )
			, linear( 0.0f )
			, quadratic( 0.0f )
		{};
	};
}


#endif