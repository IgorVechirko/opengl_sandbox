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

struct LightProperties {
	vec3 pos;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform LightProperties lightProperties;

void main()
{
	vec3 ambientLight = lightProperties.ambient * material.ambient;

	vec3 normal = normalize( fragmentNormal );
	vec3 lightDir = normalize( lightProperties.pos - fragPos );
	float intensive = max( dot(normal, lightDir), 0.0f );
	vec3 diffuseLight = ( intensive * material.diffuse ) * lightProperties.diffuse;

	vec3 viewDir = normalize( cameraPos - fragPos );
	vec3 reflectDir = reflect( -lightDir, normal );
	float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , material.shininess );
	vec3 specularLight = ( spec * material.specular )  * lightProperties.specular;

	vec4 textureColor = texture( Texture1, f_texCoord );

	color = vec4( diffuseLight + ambientLight, 1.0f );
}