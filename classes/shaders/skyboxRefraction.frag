

namespace GLSandbox
{
	const char* skyboxRefraction_frag = R"(
		#version 330 core

		in vec3 f_pos;
		in vec3 f_normal;

		out vec4 out_color;

		uniform vec3 u_cameraPos;
		uniform float u_refractCoef;
		uniform samplerCube skybox;


		void main()
		{
			vec3 viewDir = normalize( f_pos - u_cameraPos );
			vec3 refractDir = refract( viewDir, normalize(f_normal), 1.0f/u_refractCoef );

			out_color = texture(skybox, refractDir );
		}

	)";
}