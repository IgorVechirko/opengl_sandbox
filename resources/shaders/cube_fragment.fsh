#version 330 core 

in vec4 outColor;
in vec2 f_texCoord;
in vec3 fragmentNormal;
in vec3 fragPos;

out vec4 color;

uniform sampler2D Texture1;
uniform vec4 lightColor;
uniform vec3 lightSourcePos;
uniform vec3 cameraPos;

void main()
{
	vec4 ambientLight = lightColor * 0.2;

	vec3 normal = normalize( fragmentNormal );
	vec3 lightDir = normalize( lightSourcePos - fragPos );
	float intensive = max( dot(normal, lightDir), 0.0f );
	vec4 diffuseLight = intensive * lightColor;

	vec3 viewDir = normalize( cameraPos - fragPos );
	vec3 reflectDir = reflect( -lightDir, normal );
	float spec = pow( max(dot(viewDir, reflectDir), 0.0f) , 64 );
	vec4 specularLight = 0.5 * spec * lightColor;


	vec4 textureColor = texture( Texture1, f_texCoord );

	color = textureColor * ( ambientLight + diffuseLight + specularLight );
}