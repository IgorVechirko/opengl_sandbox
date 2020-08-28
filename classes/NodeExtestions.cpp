#include "NodeExtestions.h"

#include "ShaderProgram.h"

namespace GLSandbox
{


	Size3Protocol::Size3Protocol()
		: _size( 0.0f )
	{
	}
	Size3Protocol::~Size3Protocol()
	{
	}
	void Size3Protocol::setSize3( const Size3& size )
	{
		_size = size;
	}
	const Size3& Size3Protocol::getSize3()
	{
		return _size;
	}



	ShaderProtocol::ShaderProtocol()
		: _shader( nullptr )
	{
	}
	ShaderProtocol::~ShaderProtocol()
	{
		setShaderProgram( nullptr );
	}
	void ShaderProtocol::setShaderProgram( ShaderProgram* program )
	{
		if ( program != _shader )
		{
			if ( _shader )
				_shader->release();

			_shader = program;

			if ( _shader )
				_shader->retain();
		}
	}
	ShaderProgram* ShaderProtocol::getShaderProgram()
	{
		return _shader;
	}



	ColorProtocol::ColorProtocol()
	{
	}
	ColorProtocol::~ColorProtocol()
	{
	}
	void ColorProtocol::setColor( const RGBA& color )
	{
		_color = color;
	}
	const RGBA& ColorProtocol::getColor()
	{
		return _color;
	}


	

	MaterialProtocol::MaterialProtocol()
	{
	}
	MaterialProtocol::~MaterialProtocol()
	{
	}
	void MaterialProtocol::setMaterial( const Material& materila )
	{
		_material = materila;
	}
	const Material& MaterialProtocol::getMaterial()
	{
		return _material;
	}



	LigthPropertiesProtocol::LigthPropertiesProtocol()
	{
	}
	LigthPropertiesProtocol::~LigthPropertiesProtocol()
	{
	}
	void LigthPropertiesProtocol::setLightProperties( const LightProperties& properties )
	{
		_lightProperties = properties;
	}
	const LightProperties& LigthPropertiesProtocol::getLightProperties()
	{
		return _lightProperties;
	}




	LightAttenuationProtocol::LightAttenuationProtocol()
	{
	}
	LightAttenuationProtocol::~LightAttenuationProtocol()
	{
	}
	void LightAttenuationProtocol::setAttenuation( const LightAttenuationCoefs& attenuation )
	{
		_LightAttenuation = attenuation;
	}
	const LightAttenuationCoefs& LightAttenuationProtocol::getAttenuation()
	{
		return _LightAttenuation;
	}

}