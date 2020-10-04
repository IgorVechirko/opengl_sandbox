

namespace GLSandbox
{
	const char* positionUVNoMVP_vert = R"(
		#version 330 core

		layout (location = 0) in vec3 v_pos;
		layout (location = 1) in vec2 v_uvPos;

		out vec2 f_uvPos;

		void main()
		{
			gl_Position = vec4(v_pos, 1.0f);
			f_uvPos = v_uvPos;
		}
	)";
}