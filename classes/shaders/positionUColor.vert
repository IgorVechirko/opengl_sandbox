

namespace GLSandbox
{
	const char* positionUColor_vert = R"(
		#version 330 core

		layout (location = 0) in vec3 v_pos;
		
		uniform mat4 u_model;
		uniform mat4 u_view;
		uniform mat4 u_projection;

		void main()
		{
			gl_Position = u_projection * u_view * u_model * vec4( v_pos, 1.0f );
		}
	)";
} 