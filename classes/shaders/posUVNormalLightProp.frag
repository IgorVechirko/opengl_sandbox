

namespace GLSandbox
{
	const char* posUVNormalLightProp_frag = R"(
		#version 330 core

		in vec2 f_uvPos;
		in vec3 f_pos;
		in vec3 f_normal;

		out vec4 out_color;

		uniform vec3 u_cameraPos;

		struct Material {
			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
			float shininess;
		};

		struct DirectLightProperties
		{
			vec3 direction;

			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
		};

		struct PointLightProperties
		{
			vec3 pos;

			float constant;
			float linear;
			float quadratic;

			vec3 ambient;
			vec3 diffuse;
			vec3 specular;	
		};

		struct FlashlightProperties
		{
			vec3 pos;
			vec3 direction;
			float cutOffAngleCos;
			float outerCutOffAngleCos;

			float constant;
			float linear;
			float quadratic;

			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
		};

		uniform Material u_material;
		uniform DirectLightProperties u_directLight;

		#define MAX_POINT_LIGHTS 10
		uniform int u_pointLightsCount;
		uniform PointLightProperties u_pointLights[MAX_POINT_LIGHTS];

		#define MAX_FLASHLIGHTS 10
		uniform int u_flashlightsCount;
		uniform FlashlightProperties u_flashlights[MAX_FLASHLIGHTS];

		uniform sampler2D u_diffText;
		uniform sampler2D u_specText;

		vec3 calcDirectionLight( vec3 normal, vec3 viewDir )
		{
			vec3 resultColor = u_directLight.ambient * texture( u_diffText, f_uvPos ).rgb;

			vec3 lightDir = normalize( -u_directLight.direction );
			float intensive = max( dot(normal, lightDir), 0.0f );
			resultColor += ( intensive * texture( u_diffText, f_uvPos ).rgb ) * u_directLight.diffuse;

			vec3 reflectDir = reflect( -lightDir, normal );
			float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , u_material.shininess );
			resultColor += ( spec * texture( u_specText, f_uvPos ).rgb ) * u_directLight.specular;

			return resultColor;
		}

		vec3 calcPointLight( PointLightProperties lightProperties, vec3 normal, vec3 viewDir )
		{
			vec3 resultColor;

			vec3 lightDir = normalize( lightProperties.pos - f_pos );
			float intensive = max( dot(normal, lightDir), 0.0f );
			resultColor += ( intensive * texture( u_diffText, f_uvPos ).rgb ) * lightProperties.diffuse;

			vec3 reflectDir = reflect( -lightDir, normal );
			float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , u_material.shininess );
			resultColor += ( spec * texture( u_specText, f_uvPos ).rgb ) * lightProperties.specular;


			float dist = length( lightProperties.pos - f_pos );
			float attenuation = 1.0f / ( lightProperties.constant + ( lightProperties.linear * dist ) + ( lightProperties.quadratic * pow( dist, 2 ) ) );

			return resultColor * attenuation;
		}

		vec3 clacFlashlight( FlashlightProperties lightProperties, vec3 normal, vec3 viewDir )
		{
			vec3 resultColor = vec3( 0.0f, 0.0f, 0.0f );

			vec3 lightDir = normalize( lightProperties.pos - f_pos );
			float theta = dot( lightDir, normalize(-lightProperties.direction) );
			
			if ( theta > lightProperties.outerCutOffAngleCos )
			{
				float intensive = max( dot(normal, lightDir), 0.0f );
				resultColor += ( intensive * texture( u_diffText, f_uvPos ).rgb ) * lightProperties.diffuse;

				vec3 reflectDir = reflect( -lightDir, normal );
				float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , u_material.shininess );
				resultColor += ( spec * texture( u_specText, f_uvPos ).rgb )  * lightProperties.specular;


				float dist = length( lightProperties.pos - f_pos );
				float attenuation = 1.0f / ( lightProperties.constant + ( lightProperties.linear * dist ) + ( lightProperties.quadratic * pow( dist, 2 ) ) );

				
				float epsilon = lightProperties.cutOffAngleCos - lightProperties.outerCutOffAngleCos;
				float intensity = clamp((theta - lightProperties.outerCutOffAngleCos) / epsilon, 0.0f, 1.0f);

				resultColor = resultColor * attenuation * intensity;
			}

			return resultColor;
		}

		void main()
		{
			vec3 viewDir = normalize( u_cameraPos - f_pos );
			vec3 normal = normalize( f_normal );

			vec3 resultColor = vec3( 0.0f, 0.0f, 0.0f );

			resultColor += calcDirectionLight( normal, viewDir );

			for( int i = 0; i < min( u_pointLightsCount, MAX_POINT_LIGHTS ); i++ )
			{
				resultColor += calcPointLight( u_pointLights[i], normal, viewDir );
			}
			
			for( int i = 0; i < min( u_flashlightsCount, MAX_FLASHLIGHTS ); i++ )
			{
				resultColor += clacFlashlight( u_flashlights[i], normal, viewDir );
			}

			out_color = vec4( resultColor, 1.0f );
		}

	)";
}