

namespace GLSandbox
{
	const char* skyboxReflection_frag = R"(
		#version 330 core

		in vec3 f_pos;
		in vec3 f_normal;

		out vec4 out_color;

		uniform vec3 u_cameraPos;
		uniform samplerCube skybox;


		void main()
		{
			vec3 viewDir = normalize( f_pos - u_cameraPos );
			vec3 reflectionDir = reflect( viewDir, normalize(f_normal) );

			out_color = texture(skybox, reflectionDir );
		}

	)";
}