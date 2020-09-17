#include "FunctionalTestsDelegate.h"

#include "GLContext.h"
#include "ResourcesManager.h"

//test scenes
#include "TestScene.h"
#include "ResMngTest.h"
#include "DrawPrimitivesTest.h"
#include "DrawSpriteTest.h"
#include "MoveViewTest.h"
#include "DirectLightTest.h"
#include "PointLightTest.h"
#include "FlashlightTest.h"
#include "DrawModelTest.h"
#include "DrawLightningModelTest.h"
#include "DrawPointTest.h"

#include "Texture2D.h"
#include "Model.h"
#include "TexturesCache.h"

using namespace GLSandbox;

namespace FuncTests
{
	FunctionalTestsDelegate::FunctionalTestsDelegate()
		: _currentTest( -1 )
	{
	}
	FunctionalTestsDelegate::~FunctionalTestsDelegate()
	{
		getGLContext()->delInputListener( this );
	}
	void FunctionalTestsDelegate::init()
	{
		getResMng()->parseResConfig( "resdb/resources.json" );

		Console::log( "Please use keys <- and -> to switch through tests scenes" );

#ifdef _WIN32

		auto spriteTexture = createRefWithInitializer<Texture2D>( &Texture2D::initWithFilePath, getResMng()->getResPath( "MOUNTAIN" ) );
		auto model = createScopedRefWithInitializer<Model>( &Model::initWithFilePath, getResMng()->getResPath( "GUN" ) );
	
		for( const auto& texturePair : getTexturesCache()->getCachedTextures() )
			texturePair.second->setAllwaysCached( true );


		_testsCreateFuncs = { 
			std::bind( &Creator::createNode<Scene>, getCreator() ),
			std::bind( &Creator::createNode<ResMngTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawPrimitivesTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawSpriteTest>, getCreator() ),
			std::bind( &Creator::createNode<MoveViewTest>, getCreator() ),
			std::bind( &Creator::createNode<DirectLightTest>, getCreator() ),
			std::bind( &Creator::createNode<PointLightTest>, getCreator() ),
			std::bind( &Creator::createNode<FlashlightTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawModelTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawLightningModelTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawPointTest>, getCreator() )
		};
#else
		_testsCreateFuncs = { 
			//std::bind( &Creator::createNode<Scene>, getCreator() ),
			//std::bind( &Creator::createNode<ResMngTest>, getCreator() ),
			std::bind( &Creator::createNode<DrawPrimitivesTest>, getCreator() ),
			//std::bind( &Creator::createNode<DrawSpriteTest>, getCreator() ),
			std::bind( &Creator::createNode<MoveViewTest>, getCreator() ),
			std::bind( &Creator::createNode<DirectLightTest>, getCreator() ),
			std::bind( &Creator::createNode<PointLightTest>, getCreator() ),
			std::bind( &Creator::createNode<FlashlightTest>, getCreator() ),
			//std::bind( &Creator::createNode<DrawModelTest>, getCreator() ),
			//std::bind( &Creator::createNode<DrawLightningModelTest>, getCreator() )
		};
#endif

		_currentTest = 0;
		showScene( _testsCreateFuncs[0] );

		getGLContext()->addInputListener( this );
	}
	void FunctionalTestsDelegate::showNextTest()
	{
		if ( _currentTest > -1 && _currentTest < (int)_testsCreateFuncs.size() )
		{
			std::function<Scene*(void)> nextTestCreateFunc = nullptr;;
			
			if ( _currentTest == _testsCreateFuncs.size() - 1 )
			{
				_currentTest = 0;
				nextTestCreateFunc = _testsCreateFuncs[_currentTest];
			}
			else
			{
				_currentTest++;
				nextTestCreateFunc = _testsCreateFuncs[_currentTest];
			}

			showScene( nextTestCreateFunc );
		}	
	}
	void FunctionalTestsDelegate::showPrevTest()
	{
		if ( _currentTest > -1 && _currentTest < (int)_testsCreateFuncs.size() )
		{
			std::function<Scene*(void)> nextTestCreateFunc = nullptr;;
			
			if ( _currentTest == 0 )
			{
				_currentTest = _testsCreateFuncs.size() - 1;
				nextTestCreateFunc = _testsCreateFuncs[_currentTest];
			}
			else
			{
				_currentTest--;
				nextTestCreateFunc = _testsCreateFuncs[_currentTest];
			}

			showScene( nextTestCreateFunc );
		}
	}
	void FunctionalTestsDelegate::showScene( std::function<GLSandbox::Scene*(void)>& createSceneFunc )
	{
		if ( createSceneFunc )
		{
			auto scene = createSceneFunc();
			if ( scene )
				getGLContext()->setScene( scene );
		}
	}
	void FunctionalTestsDelegate::onKeyPressed( int keyCode )
	{
		if ( keyCode == GLFW_KEY_RIGHT )
			showNextTest();
		else if ( keyCode == GLFW_KEY_LEFT )
			showPrevTest();
		else if ( keyCode == GLFW_KEY_ESCAPE )
			getGLContext()->setWindowShouldClose();
	}
}