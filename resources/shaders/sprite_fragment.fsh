#version 330 core 

in vec4 outColor;
in vec2 f_texCoord;

out vec4 color;

uniform sampler2D Texture1;

void main()
{
	color = texture( Texture1, f_texCoord );
}