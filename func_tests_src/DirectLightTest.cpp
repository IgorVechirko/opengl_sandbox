#include "DirectLightTest.h"

#include "DirectLightSource.h"
#include "Cube.h"


using namespace GLSandbox;

namespace FuncTests
{
	DirectLightTest::DirectLightTest()
	{
		
	}
	DirectLightTest::~DirectLightTest()
	{
	}
	bool DirectLightTest::onInit()
	{
		Scene::onInit();

		auto directLight = createNode<DirectLightSource>();
		if ( directLight )
		{
			LightProperties lightProperties;
			lightProperties.ambient = GLSandbox::Vec3( 0.05f, 0.05f, 0.05f );
			lightProperties.diffuse = GLSandbox::Vec3( 0.5f, 0.5f, 0.5f );
			lightProperties.specular = GLSandbox::Vec3( 1.0f, 1.0f, 1.0f );

			directLight->setLightProperties( lightProperties );
			directLight->setPosition( Vec3( 0.0f, 0.0f, 700.0f ) );
			directLight->setDirection( Vec3( 0.0f, 0.0f, -1.0f ) );
			setDirectionLight( directLight );
		}

		auto cube = createNode<Cube>();
		if ( cube )
		{
			Material material;
			material.ambient = GLSandbox::Vec3( 0.0215f, 0.1745f, 0.0215f );
			material.diffuse = GLSandbox::Vec3( 0.07568f, 0.61424f, 0.07568f );
			material.specular = GLSandbox::Vec3( 0.633f, 0.727811f, 0.633f );
			material.shininess = 32.0f;

			cube->setMaterial( material );
			cube->setCubeSize( 100.0f );
			addChild( cube );
		}

		_movementController.setScope( getScope() );
		_movementController.initWithCamera( getCamera() );
		getCamera()->setPosition( Vec3( 0.0f, 0.0f, 800.0f ) );

		return true;
	}

}
