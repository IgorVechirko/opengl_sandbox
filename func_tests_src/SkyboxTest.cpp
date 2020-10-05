#include "SkyboxTest.h"


#include "ResourcesManager.h"
#include "Skybox.h"
#include "AxisesOrigin.h"
#include "OutlineSprite.h"
#include "Texture2D.h"

using namespace GLSandbox;

namespace FuncTests
{
	SkyboxTest::SkyboxTest()
	{
	}
	SkyboxTest::~SkyboxTest()
	{
	}
	bool SkyboxTest::onInit()
	{
		Scene::onInit();
		setName( "SkyboxTest" );
		Console::log( getName(), ": test scene run." );

		std::array<std::string,6> cubeMapPlatesPaths = {
			getResMng()->getResPath( "SKY_BOX_RIGHT" ),
			getResMng()->getResPath( "SKY_BOX_LEFT" ),
			getResMng()->getResPath( "SKY_BOX_TOP" ),
			getResMng()->getResPath( "SKY_BOX_BOTTOM" ),
			getResMng()->getResPath( "SKY_BOX_FRONT" ),
			getResMng()->getResPath( "SKY_BOX_BACK" )
		};

		auto skybox = createScopedRefWithInitializer<Skybox>(&Skybox::initWithPlanesPaths,cubeMapPlatesPaths );
		if ( true && skybox )
		{
			setSkybox( skybox );
		}


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

		auto origin = createNode<GLSandbox::AxisesOrigin>();
		if ( origin )
			addChild( origin );

		_cameraMovementController.setScope( getScope() );
		_cameraMovementController.initWithCamera( getCamera() );

		getCamera()->setPosition( Vec3( getCamera()->getPosition().x, getCamera()->getPosition().y, 1000.0f ) );

		return true;
	}

}
