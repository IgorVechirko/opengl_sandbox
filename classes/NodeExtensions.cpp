#include "NodeExtensions.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "GLRender.h"
#include "Node.h"

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
	const Size3& Size3Protocol::getSize3() const
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
	ShaderProgram* ShaderProtocol::getShaderProgram() const
	{
		return _shader;
	}


	Texture2DProtocol::Texture2DProtocol()
		: _texture2D( nullptr )
	{
	}
	Texture2DProtocol::~Texture2DProtocol()
	{
		setTexture2D( nullptr );
	}
	void Texture2DProtocol::setTexture2D( Texture2D* texture )
	{
		if ( texture != _texture2D )
		{
			if ( _texture2D )
				_texture2D->release();

			_texture2D = texture;

			if ( _texture2D )
				_texture2D->retain();
		}
	}
	Texture2D* Texture2DProtocol::getTexture2D() const
	{
		return _texture2D;
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
	const RGBA& ColorProtocol::getColor() const
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
	const Material& MaterialProtocol::getMaterial() const
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
	const LightProperties& LigthPropertiesProtocol::getLightProperties() const
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
	const LightAttenuationCoefs& LightAttenuationProtocol::getAttenuation() const
	{
		return _LightAttenuation;
	}



	ProtectedChildrenProtocol::ProtectedChildrenProtocol()
	{
	}
	ProtectedChildrenProtocol::~ProtectedChildrenProtocol()
	{
		for( auto child : _protectedChilds )
			child->release();
	}
	void ProtectedChildrenProtocol::visitProtectedChilds( GLRender* render, const Mat4& parentTransform )
	{
		for( auto child : _protectedChilds )
		{
			child->visit( render, parentTransform );
		}
	}
	void ProtectedChildrenProtocol::addProtectedChild( Node* child )
	{
		if ( child )
		{
			auto findIt = std::find( _protectedChilds.begin(), _protectedChilds.end(), child );
		
			if ( findIt == _protectedChilds.end() )
			{
				child->retain();
				_protectedChilds.push_back( child );
			}
		}
	}
	void ProtectedChildrenProtocol::removeProtectedChild( Node* child )
	{
		if ( child )
		{
			auto findIt = std::find( _protectedChilds.begin(), _protectedChilds.end(), child );
		
			if ( findIt != _protectedChilds.end() )
			{
				_protectedChilds.erase( findIt );
				child->release();
			}
		}
	}
	const std::vector<Node*>& ProtectedChildrenProtocol::getProtectedChildren() const
	{
		return _protectedChilds;
	}
	Node* ProtectedChildrenProtocol::getProtectedChild( const std::string& childName )
	{
		Node* result = nullptr;

		if( !childName.empty() )
		{
			auto findIt = std::find_if( _protectedChilds.begin(), _protectedChilds.end(), 
				[&childName](Node* node) -> bool
				{
					return node->getName() == childName;
				} );

			if ( findIt != _protectedChilds.end() )
			{
				result = *findIt;
			}
		}

		return result;
	}
}