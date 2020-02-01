#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

out vec4 outColor;
out vec2 f_texCoord;
out vec3 fragmentNormal;
out vec3 fragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4( position, 1.0f );
	f_texCoord = texCoord;
	fragmentNormal = mat3(transpose(inverse(model))) * normal;
	fragPos = vec3(model * vec4( position, 1.0f ));
}

