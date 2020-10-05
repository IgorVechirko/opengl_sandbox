#include "RefractionCubeTest.h"


#include "ResourcesManager.h"
#include "Skybox.h"
#include "AxisesOrigin.h"
#include "Texture2D.h"
#include "RefractionCube.h"

using namespace GLSandbox;

namespace FuncTests
{
	RefractionCubeTest::RefractionCubeTest()
	{
	}
	RefractionCubeTest::~RefractionCubeTest()
	{
	}
	bool RefractionCubeTest::onInit()
	{
		Scene::onInit();
		setName( "RefractionCubeTest" );
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

		auto colorCube = createNode<GLSandbox::RefractionCube>();

		if( colorCube )
		{
			colorCube->setRefractionCubeSize( 100.0f );
			colorCube->setRefractCoef( 1.33f );


			colorCube->setOriginShift( GLSandbox::Vec3( -50.0f, -50.0f, -50.0f ) );
			colorCube->setPosition ( GLSandbox::Vec3( 100.0f, 100.0f, 100.0f ) );
			//colorCube->setScale( Vec3( 0.5f, 0.5f, 0.5f ) );

			addChild( colorCube );
			

			_cube = colorCube;
		}

		auto origin = createNode<GLSandbox::AxisesOrigin>();
		if ( origin )
			addChild( origin );

		_cameraMovementController.setScope( getScope() );
		_cameraMovementController.initWithCamera( getCamera() );

		getCamera()->setPosition( Vec3( getCamera()->getPosition().x, getCamera()->getPosition().y, 1000.0f ) );

		scheduleUpdate();

		return true;
	}
	void RefractionCubeTest::update( float deltaTime )
	{	
		if( _cube )
		{
			_cube->setRotate( _cube->getRotate() + GLSandbox::Vec3( 20.0f, 0.0f, 20.0f ) * deltaTime );
		}
	}
}
