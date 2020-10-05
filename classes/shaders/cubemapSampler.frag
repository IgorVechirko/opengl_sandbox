

namespace GLSandbox
{
	const char* cubebapSampler_frag = R"(
		#version 330 core

		in vec3 f_uvPos;

		out vec4 out_color;

		uniform samplerCube skybox;

		void main()
		{
			out_color = texture( skybox, f_uvPos );
		}
	)";
}