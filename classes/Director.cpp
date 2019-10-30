#include "Director.h"

#include <thread>

_USEVE


Director::Director()
	: _view( nullptr )
	, _render( nullptr )
	, _camera( nullptr )
	, _fileUtils( nullptr )
	, _resMng( nullptr )
	, _scene( nullptr )
	, _releasePool( nullptr )
	, _timeScheduler( nullptr )
{
	_fileUtils = new FileUtils();
	_resMng = new ResourcesManager();

	_view = new GLView();
	_render = new GLRender();

	_releasePool = new AutoReleasePool();

	_timeScheduler = new TimeScheduler();
}
Director::~Director()
{
}
Director* Director::getInstance()
{
	static Director instance;
	return &instance;
}
void Director::init()
{
	_resMng->init();

	setCamera( Camera::create() );
	setScene( Scene::create() );

	_lastUpdateTime = std::chrono::steady_clock::now();
}
void Director::drawScene()
{
	_releasePool->chechPool();

	RENDER->drawScene( _scene );
}
float Director::calcDeltaTime()
{
	auto time = std::chrono::steady_clock::now();

	float result = std::chrono::duration_cast<std::chrono::milliseconds>( time - _lastUpdateTime ).count() / 1000.0f;

	_lastUpdateTime = time;

	LOG( "%f\n", result );

	return result;
}
void Director::loopWait()
{
	std::this_thread::sleep_for( std::chrono::milliseconds( (long)(1.0f/60.0f*1000.0f ) ) );
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
void Director::setView( GLView* view )
{
	_view = view;
}
GLView* Director::getView()
{
	return _view;
}
GLRender* Director::getRender()
{
	return _render;
}
void Director::setCamera( Camera* camera )
{
	if ( camera && camera != _camera )
	{
		if ( _camera )
		{
			_camera->release();
			_camera	= nullptr;
		}

		_camera = camera;
		_camera->retain();
	}
}
Camera* Director::getCamera()
{
	return _camera;
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