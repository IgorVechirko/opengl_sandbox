

namespace GLSandbox
{
	const char* positionNormalLightProp_vert = R"(
		#version 330 core

		layout (location = 0) in vec3 v_pos;
		layout (location = 1) in vec3 v_normal;

		out vec3 f_pos;
		out vec3 f_normal;

		uniform mat4 u_model;
		uniform mat4 u_view;
		uniform mat4 u_projection;

		void main()
		{
			gl_Position = u_projection * u_view * u_model * vec4(v_pos,1.0f);
			f_pos = vec3( u_model * vec4( v_pos, 1.0f ) );
			f_normal = mat3(transpose(inverse(u_model))) * v_normal;
		}
	)";
}