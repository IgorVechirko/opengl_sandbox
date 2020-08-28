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
			MAKE_UNCOPYABLE(ShaderProgram);

			bool initWithSrc( const std::string& verSrc, const std::string& fragSrc );

			GLuint getProgramID() const;

			void useProgram();
	};

}


#endif