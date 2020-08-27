#ifndef NodeExtentions_H
#define NodeExtentions_H

#include "VECommon.h"

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
		const Size3& getSize3();
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
		ShaderProgram* getShaderProgram();

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
		const RGBA& getColor();


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
		const LightProperties& getLightProperties();


	};


	class LightAttenuationProtocol
	{

	protected:

		LightAttenuationCoefs _LightAttenuation;

	protected:

		LightAttenuationProtocol();

	public:

		virtual ~LightAttenuationProtocol();

		void setAttenuation( const LightAttenuationCoefs& attenuation );
		const LightAttenuationCoefs& getAttenuation();


	};

}


#endif
