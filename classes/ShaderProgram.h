#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "VECommon.h"

#include "Ref.h"

_VESTART

class AutoReleasePool;
class ShaderProgram : public Ref
{

	GLuint _programID;


	ShaderProgram();

	bool init( const std::string& verSrc, const std::string& fragSrc );

	public:

		virtual ~ShaderProgram();

		static ShaderProgram* create( AutoReleasePool* pool, const std::string& verSrc, const std::string& fragSrc );

		GLuint getProgramID();

		void useProgram();
};

_VEEND


#endif