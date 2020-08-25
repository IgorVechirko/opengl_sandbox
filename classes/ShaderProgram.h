#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "VECommon.h"

#include "Ref.h"

_VESTART

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

_VEEND


#endif