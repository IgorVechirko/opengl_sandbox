#ifndef ShadersCache_H
#define ShadersCache_H

#include "WorkingScopeProvider.h"
#include "DrawTypes.h"

namespace GLSandbox
{
	
	class ShaderProgram;
	class ShadersCache : public WorkingScopeProvider
	{

		std::map<StandartShaderType, ShaderProgram*> _standartShaders;
		std::map<std::string, ShaderProgram*> _customShaders;


	public:

		ShadersCache();
		virtual ~ShadersCache();
		MAKE_UNCOPYABLE( ShadersCache );

		void init();

		ShaderProgram* getStandartShader( StandartShaderType type );
		
		ShaderProgram* createShader( const std::string& vertPath, const std::string& fragPath );
	};

}


#endif