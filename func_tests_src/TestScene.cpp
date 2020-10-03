#include "TestScene.h"

#include "Sprite.h"
#include "Cube.h"

#include "PointLightSource.h"
#include "DirectLightSource.h"
#include "ColorCube.h"
#include "Line.h"
#include "AxisesOrigin.h"
#include "PointLightSource.h"
#include "Flashlight.h"
#include "Model.h"
#include "ShaderProgram.h"
#include "ResourcesManager.h"
#include "FileUtils.h"
#include "Texture2D.h"
#include "OutlineSprite.h"

using namespace GLSandbox;

namespace FuncTests
{

	TestScene::TestScene()
		: _mySprite( nullptr )
		, _cube( nullptr )
	{
	}
	TestScene::~TestScene()
	{
	}
	bool TestScene::onInit()
	{
		Parent::onInit();

		if ( true )
		{
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
		}


		if ( false )
		{
			_mySprite = createScopedRefWithInitializer<GLSandbox::Sprite>(&GLSandbox::Sprite::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
			if ( _mySprite )
			{
				addChild( _mySprite );
			}
		}

		if ( false  && _mySprite )
		{
			auto line = createNode<GLSandbox::Line>();
			if ( line )
			{
				line->setColor( { 0.0f, 1.0f, 0.0f, 1.0f } );
				line->setFinishPos( GLSandbox::Vec3(_mySprite->getTexture2D()->getWidth(), _mySprite->getTexture2D()->getHeight(), 0.0f ) );
				line->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, 10.0f ) );

				addChild( line );
			}
		}

		if( true )
		{
			auto origin = createNode<GLSandbox::AxisesOrigin>();
			addChild( origin );
		}

		if ( false )
		{
			auto newModel = createScopedRefWithInitializer<GLSandbox::Model>(&GLSandbox::Model::initWithFilePath, getResMng()->getResPath( "GUN" ) );
			if ( newModel )
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
					auto model = newModel->getChild( modelName );
					if ( model )
						model->setVisbile( false );
				}

				for( auto model : newModel->getSubModels() )
				{
					Console::log( "Node name: ", model->getName() );
				}

				//newModel->setPosition( GLSandbox::Vec3( 100.0f ) );
				addChild( newModel );
			}
		}

		GLSandbox::Material emerald;
		emerald.ambient = GLSandbox::Vec3( 0.0215f, 0.1745f, 0.0215f );
		emerald.diffuse = GLSandbox::Vec3( 0.07568f, 0.61424f, 0.07568f );
		emerald.specular = GLSandbox::Vec3( 0.633f, 0.727811f, 0.633f );
		emerald.shininess = 32.0f;

		/*if( false )
		{
			for( int i = 0; i < 3; i++ )
			{
				for( int j = 0; j < 3; j++ )
				{
					for( int z = 0; z < 3; z++ )
					{
						auto cube = createScopedRefWithInitializer<GLSandbox::Cube>( &GLSandbox::Cube::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
						cube->setMaterial( emerald );
						cube->setPosition( GLSandbox::Vec3( 1400.0f*i, 1400.0f*j, -1400.0f*z ) );
						cube->setRotate( GLSandbox::Vec3( 10.0f*i, 10.0f*j, 10.0f*z ) );
						cube->setOriginShift( GLSandbox::Vec3( -200.0f ) );

						addChild( cube );
					}
				}
			}
		}*/

		if( false )
		{
			auto cube = createNode<GLSandbox::Cube>();
			cube->setCubeSize( 100.0f );
			cube->setMaterial( emerald );
			//cube->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, -500.0f ) );
			cube->setOriginShift( GLSandbox::Vec3( -50.0f ) );
			cube->setScale( GLSandbox::Vec3( 3.0f, 3.0f, 3.0f ) );

			addChild( cube );
			//_cube = cube;
		}

		if ( false )
		{
			auto colorCube = createNode<GLSandbox::ColorCube>();

			colorCube->setColor( GLSandbox::RGBA::RED );
			colorCube->setCubeSize( 100.0f );
			colorCube->setOriginShift( GLSandbox::Vec3( -50.0f, -50.0f, -50.0f ) );
			colorCube->setPosition ( GLSandbox::Vec3( 100.0f, 100.0f, 100.0f ) );
			//colorCube->setScale( Vec3( 0.5f, 0.5f, 0.5f ) );

			addChild( colorCube );

			_cube = colorCube;
		}

		GLSandbox::LightProperties lightProperties;
		lightProperties.ambient = GLSandbox::Vec3( 0.05f, 0.05f, 0.05f );
		lightProperties.diffuse = GLSandbox::Vec3( 0.5f, 0.5f, 0.5f );
		lightProperties.specular = GLSandbox::Vec3( 1.0f, 1.0f, 1.0f );

		GLSandbox::LightAttenuationCoefs attenuation;
		attenuation.constant = 1.0f;
		attenuation.linear = 0.000014f;
		attenuation.quadratic = 0.0000007f;

	
		if ( false )
		{
			GLSandbox::DirectLightSource* directionLight = createNode<GLSandbox::DirectLightSource>();
			directionLight->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, 1000.0f ) );
			directionLight->setDirection( GLSandbox::Vec3( 0.0f, 0.0f, -1.0f ) );

		
			directionLight->setLightProperties( lightProperties );

			setDirectionLight( directionLight );
		}

		if ( false )
		{
			float dist = 400.0f;
			std::vector<GLSandbox::Vec3> lightsPositions;
			lightsPositions.push_back( GLSandbox::Vec3( 0.0f, 0.0f, 50.0f ) );
			/*lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, 0.0f ) );
			lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( 0.0f, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, 0.0f ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, dist ) );*/

			for( const auto& pos : lightsPositions )
			{
				auto pointLight = createNode<GLSandbox::PointLightSource>();
				pointLight->setLightProperties( lightProperties );
				pointLight->setAttenuation( attenuation );
				pointLight->setPosition( pos );

				addPointLight( pointLight );
			}
		}

		if ( false )
		{
			auto light = createNode<GLSandbox::Flashlight>();

			light->setAttenuation( attenuation );
			light->setLightProperties( lightProperties );
			light->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, 600.0f ) );
			light->setDirection( GLSandbox::Vec3( 0.0f, 0.0f, -1.0f ) );
			light->setCutOffAngle( 12.5f );
			light->setOuterCutOffAngle( 17.0f );
		
			addFlashlight( light );
		}
	
		_cameraMovementController.setScope( getScope() );
		_cameraMovementController.initWithCamera( getCamera() );

		getCamera()->setPosition( Vec3( getCamera()->getPosition().x, getCamera()->getPosition().y, 1000.0f ) );
		scheduleUpdate();

		return true;
	}
	void TestScene::update( float deltaTime )
	{	
		if( _cube )
		{
			/*if ( _cube->getScale().x <= -1.0f )
			{
				_cube->setScale( Vec3( 1.0f ) );
			}

			_cube->setScale( _cube->getScale() - Vec3( 0.1f ) * deltaTime );

			*/_cube->setRotate( _cube->getRotate() + GLSandbox::Vec3( 20.0f, 0.0f, 20.0f ) * deltaTime );
		}
	}

}