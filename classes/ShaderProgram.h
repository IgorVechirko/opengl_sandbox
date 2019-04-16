#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "VECommon.h"

_VESTART

class ShaderProgram
{

	GLuint _programID;

	public:

		ShaderProgram( const std::string& verPath, const std::string& fragPath );
		virtual ~ShaderProgram();

		GLuint getProgramID();
};

_VEEND


#endif