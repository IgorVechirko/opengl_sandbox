#include "PointLightTest.h"

#include "PointLightSource.h"
#include "Cube.h"


using namespace GLSandbox;

namespace FuncTests
{
	PointLightTest::PointLightTest()
	{
		
	}
	PointLightTest::~PointLightTest()
	{
	}
	bool PointLightTest::onInit()
	{
		Scene::onInit();
		setName( "PointLightTest" );
		Console::log( getName(), ": test scene run. Please use a,w,s,d,r,f for move and mouse for rotate camera." );

		auto pointLight = createNode<PointLightSource>();
		if ( pointLight )
		{
			LightProperties lightProperties;
			lightProperties.ambient = GLSandbox::Vec3( 0.05f, 0.05f, 0.05f );
			lightProperties.diffuse = GLSandbox::Vec3( 0.5f, 0.5f, 0.5f );
			lightProperties.specular = GLSandbox::Vec3( 1.0f, 1.0f, 1.0f );

			GLSandbox::LightAttenuationCoefs attenuation;
			attenuation.constant = 1.0f;
			attenuation.linear = 0.000014f;
			attenuation.quadratic = 0.0000007f;

			pointLight->setLightProperties( lightProperties );
			pointLight->setAttenuation( attenuation );
			pointLight->setPosition( Vec3( 0.0f, 0.0f, 700.0f ) );
			addPointLight( pointLight );
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
