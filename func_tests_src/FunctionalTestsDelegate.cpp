#include "FunctionalTestsDelegate.h"

#include "GLContext.h"
#include "ResourcesManager.h"

//test scenes
#include "TestScene.h"
#include "ResMngTest.h"

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

		_testsCreateFuncs = { 
			std::bind( &Creator::createNode<Scene>, getCreator() ),
			std::bind( &Creator::createNode<ResMngTest>, getCreator() )
		};

		_currentTest = 0;

		getGLContext()->addInputListener( this );
	}
	void FunctionalTestsDelegate::showNextTest()
	{
		if ( _currentTest > -1 && _currentTest < _testsCreateFuncs.size() )
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
		if ( _currentTest > -1 && _currentTest < _testsCreateFuncs.size() )
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