#version 330 core 

in vec4 outColor;
in vec2 f_texCoord;
in vec3 fragmentNormal;
in vec3 fragPos;

out vec4 color;

uniform sampler2D Texture1;
uniform vec3 cameraPos;

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

uniform Material material;
uniform DirectLightProperties directLight;

#define MAX_POINT_LIGHTS 4
uniform int pointLightsCount;
uniform PointLightProperties pointLights[MAX_POINT_LIGHTS];

vec3 calcDirectionLight( vec3 normal, vec3 viewDir )
{
	vec3 resultColor = directLight.ambient * material.ambient;

	vec3 lightDir = normalize( -directLight.direction );
	float intensive = max( dot(normal, lightDir), 0.0f );
	resultColor += ( intensive * material.diffuse ) * directLight.diffuse;

	vec3 reflectDir = reflect( -lightDir, normal );
	float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , material.shininess );
	resultColor += ( spec * material.specular )  * directLight.specular;


	return resultColor;
}

vec3 calcPointLight( PointLightProperties lightProperties, vec3 normal, vec3 viewDir )
{
	vec3 resultColor = lightProperties.ambient * material.ambient;

	vec3 lightDir = normalize( lightProperties.pos - fragPos );
	float intensive = max( dot(normal, lightDir), 0.0f );
	resultColor += ( intensive * material.diffuse ) * lightProperties.diffuse;

	vec3 reflectDir = reflect( -lightDir, normal );
	float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , material.shininess );
	resultColor *= ( spec * material.specular )  * lightProperties.specular;


	float dist = length( lightProperties.pos - fragPos );
	float attenuation = 1.0f / lightProperties.constant + ( lightProperties.linear * dist ) + ( lightProperties.quadratic * pow( dist, 2 ) );

	return resultColor * attenuation;
}



void main()
{
	vec3 normal = normalize( fragmentNormal );
	vec3 viewDir = normalize( cameraPos - fragPos );

	vec3 resultColor = calcDirectionLight( normal, viewDir );

	for( int i = 0; i < min( 0, MAX_POINT_LIGHTS ); i++ )
	{
		resultColor += calcPointLight( pointLights[i], normal, viewDir );
	}
	

	vec4 textureColor = texture( Texture1, f_texCoord );

	color = vec4( resultColor, 1.0f );
}