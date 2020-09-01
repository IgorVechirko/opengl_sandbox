

namespace GLSandbox
{
	const char* positionUVTexture_frag = R"(
		#version 330 core

		in vec2 f_uvPos;

		out vec4 out_color;

		uniform sampler2D u_Texture1;

		void main()
		{
			out_color = texture( u_Texture1, f_uvPos );
		}
	)";
}