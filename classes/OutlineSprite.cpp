#include "OutlineSprite.h"

#include "ShaderProgram.h"
#include "ShadersCache.h"
#include "Texture2D.h"
#include "GLContext.h"
#include "Scene.h"
#include "OpenGL.h"

namespace GLSandbox
{
	OutlineSprite::OutlineSprite()
		: _outlineColor( RGBA::GRAY )
		, _outlineCoef( 0.01f )
	{
	}
	OutlineSprite::~OutlineSprite()
	{
	}
	bool OutlineSprite::onInit()
	{
		_outlineShaderProtocol.setShaderProgram( getShadersCache()->getStandartShader(StandartShaderType::POS_UCOLOR) );

		return true;
	}
	void OutlineSprite::drawTraversal( const Mat4& parentTransform )
	{
		auto transform = parentTransform * getTransform();

		glStencilMask( 0xFF );
		glClear( GL_STENCIL_BUFFER_BIT );
		glStencilFunc( GL_ALWAYS, 1, 0xFF );
		Sprite::draw( transform );
		glStencilMask( 0x00 );

		auto prevScale = getScale();
		setScale( Vec3( prevScale.x + _outlineCoef, prevScale.y + _outlineCoef, prevScale.z ) );
		transform = parentTransform * getTransform();

		glStencilFunc( GL_NOTEQUAL, 1, 0xFF );


		if( getTexture2D() )
			getTexture2D()->useTexture();

		auto outlineShader = _outlineShaderProtocol.getShaderProgram();

		if( outlineShader )
		{
			outlineShader->useProgram();
			auto scene = getGLContext()->getScene();

			outlineShader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );
			outlineShader->setUniform4f( "u_color", _outlineColor.r, _outlineColor.g, _outlineColor.b, _outlineColor.a );
			scene->setViewToShader( outlineShader );
			scene->setProjectionToShader( outlineShader );
		}

		_arrayBuffer.drawElements( GL_TRIANGLES, GL_UNSIGNED_INT, 0 );

		setScale( prevScale );
	}
	ShaderProtocol& OutlineSprite::getOutlineShaderProtocol()
	{
		return _outlineShaderProtocol;
	}
	void OutlineSprite::setOutlineCoef( float coef )
	{
		if ( coef >= 0.0f )
			_outlineCoef = coef;
	}
	float OutlineSprite::getOutlineCoef()
	{
		return _outlineCoef;
	}
}