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

namespace WorkingTests
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

		if( false )
		{
			auto origin = createNode<GLSandbox::AxisesOrigin>();
			addChild( origin );
		}

		if ( false )
		{
			auto model = createNode<GLSandbox::Model>();
			model->loadModel( getResMng()->getResPath( "GUN" ) );
			model->setShaderProgram( createRefWithInitializer<GLSandbox::ShaderProgram>(&GLSandbox::ShaderProgram::initWithSrc, getResMng()->getResStr( "MODEL_VERTEX" ), getResMng()->getResStr( "MODEL_FRAGMENT" ) ) );
			addChild( model );
		}

		GLSandbox::Material emerald;
		emerald.ambient = GLSandbox::Vec3( 0.0215f, 0.1745f, 0.0215f );
		emerald.diffuse = GLSandbox::Vec3( 0.07568f, 0.61424f, 0.07568f );
		emerald.specular = GLSandbox::Vec3( 0.633f, 0.727811f, 0.633f );
		emerald.shininess = 32.0f;

		if( true )
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
		}

		if( false )
		{
			auto cube = createScopedRefWithInitializer<GLSandbox::Cube>( &GLSandbox::Cube::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
			cube->setMaterial( emerald );
			cube->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, -500.0f ) );
			cube->setOriginShift( GLSandbox::Vec3( -200.0f ) );
			cube->setScale( GLSandbox::Vec3( 3.0f, 3.0f, 3.0f ) );

			addChild( cube );
			_cube = cube;
		}

		if ( false )
		{
			auto colorCube = createNode<GLSandbox::ColorCube>();

			//colorCube->setColor( RGBA::RED );
			colorCube->setCubeSize( 100.0f );
			colorCube->setOriginShift( GLSandbox::Vec3( -50.0f, -50.0f, -50.0f ) );
			colorCube->setPosition ( GLSandbox::Vec3( 100.0f, 100.0f, 100.0f ) );
			//colorCube->setScale( Vec3( 0.5f, 0.5f, 0.5f ) );

			addChild( colorCube );

			_cube = colorCube;
		}

		GLSandbox::LightProperties lightProperties;
		lightProperties.ambient = GLSandbox::Vec3( 0.2f, 0.2f, 0.2f );
		lightProperties.diffuse = GLSandbox::Vec3( 0.5f, 0.5f, 0.5f );
		lightProperties.specular = GLSandbox::Vec3( 1.0f, 1.0f, 1.0f );

		GLSandbox::LightAttenuationCoefs attenuation;
		attenuation.constant = 1.0f;
		attenuation.linear = 0.000014f;
		attenuation.quadratic = 0.0000007f;

	
		if ( true )
		{
			GLSandbox::DirectLightSource* directionLight = createNode<GLSandbox::DirectLightSource>();
			directionLight->setPosition( GLSandbox::Vec3( 0.0f, 0.0f, 1000.0f ) );
			directionLight->setDirection( GLSandbox::Vec3( 1.0f, 0.0f, 0.0f ) );

		
			directionLight->setLightProperties( lightProperties );

			setDirectionLight( directionLight );
		}

		if ( true )
		{
			float dist = 400.0f;
			std::vector<GLSandbox::Vec3> lightsPositions;
			lightsPositions.push_back( GLSandbox::Vec3( 2.0f*dist, 2.0f*dist, -2.0f*dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, 0.0f ) );
			lightsPositions.push_back( GLSandbox::Vec3( -dist, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( 0.0f, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, -dist ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, 0.0f ) );
			lightsPositions.push_back( GLSandbox::Vec3( dist, 0.0f, dist ) );

			for( const auto& pos : lightsPositions )
			{
				auto pointLight = createNode<GLSandbox::PointLightSource>();
				pointLight->setLightProperties( lightProperties );
				pointLight->setAttenuation( attenuation );
				pointLight->setPosition( pos );

				addPointLight( pointLight );
			}
		}

		if ( true )
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