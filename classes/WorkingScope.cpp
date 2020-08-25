#include "WorkingScope.h"

#include "WorkingScope.h"
#include "GLView.h"
#include "GLRender.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "AutoReleasePool.h"
#include "TimeScheduler.h"
#include "InputController.h"
#include "Scene.h"
#include "TestScene.h"

#include <thread>

_USEVE

WorkingScope::WorkingScope()
	: _view( nullptr )
	, _render( nullptr )
	, _fileUtils( nullptr )
	, _resMng( nullptr )
	, _releasePool( nullptr )
	, _timeScheduler( nullptr )
	, _inputController( nullptr )
	, _scene( nullptr )
{
	_fileUtils = new FileUtils(this);
	_resMng = new ResourcesManager(this);

	_view = new GLView(this);
	_render = new GLRender(this);

	_releasePool = new AutoReleasePool(this);

	_timeScheduler = new TimeScheduler(this);

	_inputController = new InputController(this);
}
WorkingScope::~WorkingScope()
{
	delete _fileUtils;
	delete _resMng;

	delete _view;
	delete _render;

	delete _releasePool;

	delete _timeScheduler;

	delete _inputController;
}
void WorkingScope::drawScene()
{
	_releasePool->checkPool();

	_render->drawScene( _scene );
}
float WorkingScope::calcDeltaTime()
{
	auto time = std::chrono::steady_clock::now();

	float result = std::chrono::duration_cast<std::chrono::milliseconds>( time - _lastUpdateTime ).count() / 1000.0f;

	_lastUpdateTime = time;

	return result;
}
void WorkingScope::loopWait()
{
	std::this_thread::sleep_for( std::chrono::milliseconds( (long)( (1.0f/60.0f) * 1000.0f ) ) );
}
GLView* WorkingScope::getGLView()
{
	return _view;
}
GLRender* WorkingScope::getRender()
{
	return _render;
}
FileUtils* WorkingScope::getFileUtils()
{
	return _fileUtils;
}
ResourcesManager* WorkingScope::getResMng()
{
	return _resMng;
}
AutoReleasePool* WorkingScope::getReleasePool()
{
	return _releasePool;
}
TimeScheduler* WorkingScope::getTimeScheduler()
{
	return _timeScheduler;
}
InputController* WorkingScope::getInputController()
{
	return _inputController;
}
void WorkingScope::setScene( Scene* scene )
{
	if ( _scene != scene )
	{
		if ( _scene )
		{
			_scene->release();
		}

		_scene = scene;
	}
}
Scene* WorkingScope::getScene()
{
	return _scene;
}
void WorkingScope::startWork()
{
	_resMng->init();

	Size winSize(1024, 768 );
	_view->setupWindowSize( winSize.x, winSize.y );
	_inputController->init();

	setScene( TestScene::create(this) );

	while( !glfwWindowShouldClose(_view->getWindow() ) )
	{
		_timeScheduler->onMainTick( calcDeltaTime() );
		drawScene();
		loopWait();
	}

	glfwTerminate();
}
