#include "ShadersCache.h"

#include "ShaderProgram.h"
#include "FileUtils.h"


namespace GLSandbox
{

	ShadersCache::ShadersCache()
	{
	}
	ShadersCache::~ShadersCache()
	{
		for( auto& shaderPair : _standartShaders )
			shaderPair.second->release();

		for( auto& shaderPair : _customShaders )
			shaderPair.second->release();
	}
	void ShadersCache::init()
	{
		_standartShaders[ StandartShaderType::POS_UCOLOR ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionUColor_vert, positionUColor_frag );
		_standartShaders[ StandartShaderType::POS_NORMAL_LIGHT_PROP ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionNormalLightProp_vert, positionNormalLightProp_frag );
		_standartShaders[ StandartShaderType::POS_UV_TEXTURE ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionUVTexture_vert, positionUVTexture_frag );
		_standartShaders[ StandartShaderType::POS_UV_NORMAL_LIGHT_PORP ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, posUVNormalLightProp_vert, posUVNormalLightProp_frag );
		_standartShaders[ StandartShaderType::NO_MVP_POS_UV_TEXTURE ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionUVNoMVP_vert, positionUVTexture_frag );
		_standartShaders[ StandartShaderType::NO_MODEL_CUBE_SAMPLER ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionNoModel_vert, cubebapSampler_frag );
		_standartShaders[ StandartShaderType::POS_NORMAL_SKYBOX_REFLECTION ] = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionNormalLightProp_vert, skyboxReflection_frag );

		for( auto& shaderPair : _standartShaders )
			shaderPair.second->retain();
	}
	ShaderProgram* ShadersCache::getStandartShader( StandartShaderType type )
	{
		return _standartShaders[ type ];
	}
	ShaderProgram* ShadersCache::createShader( const std::string& vertPath, const std::string& fragPath )
	{
		ShaderProgram* result = nullptr;

		auto shaderKey = fragPath + vertPath;
		auto findIt = _customShaders.find( shaderKey );
		if( findIt != _customShaders.end() )
		{
			result = findIt->second;
		}
		else
		{
			result = createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, getFileUtils()->getStringFromFile( vertPath ), getFileUtils()->getStringFromFile( fragPath ) );
			if ( result )
			{
				result->retain();
				_customShaders[shaderKey] = result;
			}
		}

		return result;
	}

}