#include "FrameBufferTest.h"

#include "AxisesOrigin.h"
#include "OutlineSprite.h"
#include "ResourcesManager.h"
#include "Texture2D.h"

using namespace GLSandbox;

namespace FuncTests
{
	FrameBufferTest::FrameBufferTest()
		: _frameBuffer( nullptr )
	{
	}
	FrameBufferTest::~FrameBufferTest()
	{
		if ( _frameBuffer )
			_frameBuffer->release();
	}
	bool FrameBufferTest::onInit()
	{
		Scene::onInit();

		_frameBuffer = createNode<CustomFrameBuffer>();
		if ( _frameBuffer )
		{
			_frameBuffer->retain();
		}

		auto origin = createNode<GLSandbox::AxisesOrigin>();
		if( origin )
			addChild( origin );

		auto outlineSprite1 = createScopedRefWithInitializer<OutlineSprite>( &OutlineSprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
		if ( outlineSprite1 )
		{
			outlineSprite1->setName( "1" );
			outlineSprite1->setOriginShift( Vec3( -outlineSprite1->getTexture2D()->getWidth()/2.0f, -outlineSprite1->getTexture2D()->getHeight()/2.0f, -1.0f ) );
			addChild( outlineSprite1 );
		}

		auto outlineSprite2 = createScopedRefWithInitializer<OutlineSprite>( &OutlineSprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
		if ( outlineSprite2 )
		{
			outlineSprite2->setName( "2" );
			outlineSprite2->setOriginShift( Vec3( -outlineSprite2->getTexture2D()->getWidth()/2.0f, -outlineSprite2->getTexture2D()->getHeight()/2.0f, -1.0f ) );
			outlineSprite2->setPosition( Vec3( 100.0f, -25.0f, 100.0f ) );
			addChild( outlineSprite2 );
		}

		_cameraMovementController.setScope( getScope() );
		_cameraMovementController.initWithCamera( getCamera() );

		return true;
	}
	void FrameBufferTest::onBeforeDraw()
	{
		if ( _frameBuffer )
		{
			_frameBuffer->bind();
			_frameBuffer->onBeforeStartDraw();
			Scene::drawTraversal( Mat4(1.0f) );
			_frameBuffer->onDrawFinish();
			_frameBuffer->unbind();
		}
	}
	void FrameBufferTest::drawTraversal( const Mat4& parentTransform )
	{
		if ( _frameBuffer && true )
			_frameBuffer->Node::drawTraversal( parentTransform );
		else
			Scene::drawTraversal( parentTransform );
	}

}
