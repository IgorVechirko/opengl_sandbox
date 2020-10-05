

namespace GLSandbox
{
	const char* positionNoModel_vert = R"(
		#version 330 core

		layout (location = 0) in vec3 v_pos;

		out vec3 f_uvPos;

		uniform mat4 u_view;
		uniform mat4 u_projection;

		void main()
		{
			gl_Position = u_projection * u_view * vec4(v_pos, 1.0);
    		gl_Position.z = gl_Position.w;

			f_uvPos = v_pos;
		}
		
	)";
}