#include "DrawLightningModelTest.h"

#include "Model.h"
#include "ResourcesManager.h"
#include "ShadersCache.h"
#include "DirectLightSource.h"

using namespace GLSandbox;

namespace FuncTests
{
	DrawLightningModelTest::DrawLightningModelTest()
	{
	}
	DrawLightningModelTest::~DrawLightningModelTest()
	{
	}
	bool DrawLightningModelTest::onInit()
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

		auto model = createScopedRefWithInitializer<Model>(&Model::initWithFilePath, getResMng()->getResPath( "GUN" ) );
		if ( model )
		{
			std::vector<std::string> invisibleModels = { 
			"bullet_Cube.005",
			//"Cube.002_Cube.003",
			"hulle_Cube",
			//"Gun_Cube.001",
			//"Cube.005_Cube.000",
			"muzzle_fire_Plane.002",
			//"Gun_trigger_Cube.002"
				};

			for( const auto& modelName : invisibleModels )
			{
				auto subModel = model->getChild( modelName );
				if ( subModel )
					subModel->setVisbile( false );
			}

			addChild( model );
		}

		_movementController.setScope( getScope() );
		_movementController.setMovementSpeed( 1.0f );
		_movementController.initWithCamera( getCamera() );

		getCamera()->setPosition( Vec3( 0.0f, 0.0f, 5.0f ) );

		return true;
	}

}
