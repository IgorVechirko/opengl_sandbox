#ifndef NodeExtensions_H
#define NodeExtensions_H

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

	class Texture2D;
	class Texture2DProtocol
	{

	protected:

		Texture2D* _texture2D;

	protected:

		Texture2DProtocol();

	public:

		virtual ~Texture2DProtocol();

		virtual void setTexture2D( Texture2D* texture );
		virtual Texture2D* getTexture2D() const;

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

	class Node;
	class GLRender;
	class ProtectedChildsProtocol
	{
		std::vector<Node*> _protectedChilds;

	public:

		ProtectedChildsProtocol();
		virtual ~ProtectedChildsProtocol();

		virtual void visitProtectedChilds( GLRender* render, const Mat4& parentTransform );

		virtual void addProtectedChild( Node* child );
		virtual void removeProtectedChild( Node* child );

		virtual const std::vector<Node*>& getProtectedChildren() const;
		virtual Node* getProtectedChild( const std::string& childName );

		template<typename T>
		T* getProtectedChild( const std::string& childName )
		{
			return dynamic_cast<T>( getProtectedChild(childName) );
		}

	};

}


#endif
