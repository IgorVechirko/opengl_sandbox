#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "Common.h"

#include "Ref.h"


namespace GLSandbox
{

	class AutoReleasePool;
	class ShaderProgram : public Ref
	{

		GLuint _programID;


	


		public:

			ShaderProgram();
			virtual ~ShaderProgram();

			bool initWithSrc( const std::string& verSrc, const std::string& fragSrc );

			GLuint getProgramID();

			void useProgram();
	};

}


#endif