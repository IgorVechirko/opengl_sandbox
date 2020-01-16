#include "Director.h"

#include <thread>

_USEVE


Director::Director()
	: _view( nullptr )
	, _render( nullptr )
	, _fileUtils( nullptr )
	, _resMng( nullptr )
	, _scene( nullptr )
	, _releasePool( nullptr )
	, _timeScheduler( nullptr )
	, _inputController( nullptr )
{
	_fileUtils = new FileUtils();
	_resMng = new ResourcesManager();

	_view = new GLView();
	_render = new GLRender();

	_releasePool = new AutoReleasePool();

	_timeScheduler = new TimeScheduler();

	_inputController = new InputController();
}
Director::~Director()
{
	delete _fileUtils;
	delete _resMng;
	delete _view;
	delete _render;
	delete _releasePool;
	delete _timeScheduler;
}
Director* Director::getInstance()
{
	static Director instance;
	return &instance;
}
void Director::init()
{
	_resMng->init();

	_lastUpdateTime = std::chrono::steady_clock::now();
}
void Director::drawScene()
{
	_releasePool->checkPool();

	_render->drawScene( _scene );
}
float Director::calcDeltaTime()
{
	auto time = std::chrono::steady_clock::now();

	float result = std::chrono::duration_cast<std::chrono::milliseconds>( time - _lastUpdateTime ).count() / 1000.0f;

	_lastUpdateTime = time;

	return result;
}
void Director::loopWait()
{
	std::this_thread::sleep_for( std::chrono::milliseconds( (long)( (1.0f/60.0f) * 1000.0f ) ) );
}
void Director::runMainLoop()
{
	while( true )
	{
		_timeScheduler->onMainTick( calcDeltaTime() );

		drawScene();

		loopWait();
	}
}
GLView* Director::getView()
{
	return _view;
}
GLRender* Director::getRender()
{
	return _render;
}
void Director::setScene( Scene* scene )
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
Scene* Director::getScene()
{
	return _scene;
}
FileUtils* Director::getFileUtils()
{
	return _fileUtils;
}
ResourcesManager* Director::getResMng()
{
	return _resMng;
}
AutoReleasePool* Director::getReleasePool()
{
	return _releasePool;
}
TimeScheduler* Director::getTimeScheduler()
{
	return _timeScheduler;
}
InputController* Director::getInputController()
{
	return _inputController;
}