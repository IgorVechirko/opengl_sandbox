#ifndef NodeExtestions_H
#define NodeExtestions_H

#include "Common.h"
#include "MaterialsAndLightsTypes.h"

namespace GLSandbox
{


	class Size3Protocol
	{

	protected:

		Size3 _size;
	

	protected:

		Size3Protocol();

	public:

		virtual ~Size3Protocol();

		virtual void setSize3( const Size3& size );
		virtual const Size3& getSize3() const;
	};

	class ShaderProgram;
	class ShaderProtocol
	{

	protected:

		ShaderProgram* _shader;

	protected:

		ShaderProtocol();

	public:

		virtual ~ShaderProtocol();

		virtual void setShaderProgram( ShaderProgram* program );
		virtual ShaderProgram* getShaderProgram() const;

	};

	class ColorProtocol
	{

	protected:

		RGBA _color;

	protected:
		
		ColorProtocol();

	public:

		virtual ~ColorProtocol();

		virtual void setColor( const RGBA& color );
		virtual const RGBA& getColor() const;


	};

	class MaterialProtocol
	{

		Material _material;

	protected:

		MaterialProtocol();

	public:

		virtual ~MaterialProtocol();

		virtual void setMaterial( const Material& material );
		virtual const Material& getMaterial() const;
	};

	class LigthPropertiesProtocol
	{

	protected:

		LightProperties _lightProperties;

	protected:

		LigthPropertiesProtocol();

	public:

		virtual ~LigthPropertiesProtocol();

		virtual void setLightProperties( const LightProperties& properties );
		virtual const LightProperties& getLightProperties() const;


	};


	class LightAttenuationProtocol
	{

	protected:

		LightAttenuationCoefs _LightAttenuation;

	protected:

		LightAttenuationProtocol();

	public:

		virtual ~LightAttenuationProtocol();

		virtual void setAttenuation( const LightAttenuationCoefs& attenuation );
		virtual const LightAttenuationCoefs& getAttenuation() const;


	};

}


#endif
