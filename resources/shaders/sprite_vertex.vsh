#version 330 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec3 color;
layout (location = 1) in vec2 texCoord;

out vec4 outColor;
out vec2 f_texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4( position, 1.0f );
	outColor = vec4(color, 0.1f);
	f_texCoord = texCoord;
}

