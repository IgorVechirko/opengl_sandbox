#version 330 core

in vec2 fragmentTextCoord;

out vec4 fragmentColor;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{
	fragmentColor = texture( texture_diffuse1, fragmentTextCoord );
}