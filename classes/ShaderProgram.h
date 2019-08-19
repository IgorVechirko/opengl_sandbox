#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "VECommon.h"

#include "Ref.h"

_VESTART

class ShaderProgram : public Ref
{

	GLuint _programID;


	ShaderProgram();

	bool init( const std::string& verPath, const std::string& fragPath );

	public:

		virtual ~ShaderProgram();

		static ShaderProgram* create( const std::string& verPath, const std::string& fragPath );

		GLuint getProgramID();

		void useProgram();
};

_VEEND


#endif