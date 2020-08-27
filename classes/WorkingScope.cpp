#include "WorkingScope.h"

#include "WorkingScope.h"
#include "GLRender.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "AutoReleasePool.h"
#include "TimeScheduler.h"
#include "Scene.h"
#include "TestScene.h"
#include "GLContext.h"

#include <thread>

_USEVE

WorkingScope::WorkingScope()
	: _render( nullptr )
	, _glContext( nullptr )
	, _fileUtils( nullptr )
	, _resMng( nullptr )
	, _releasePool( nullptr )
	, _timeScheduler( nullptr )
	, _scene( nullptr )
{
	_fileUtils = new FileUtils(this);
	_resMng = new ResourcesManager(this);

	_glContext = createObjWithInitializer<GLContext>(&GLContext::initWithWndSize, 1024, 768 );
	_render = new GLRender(this);

	_releasePool = new AutoReleasePool(this);

	_timeScheduler = new TimeScheduler(this);
}
WorkingScope::~WorkingScope()
{
	delete _fileUtils;
	delete _resMng;

	delete _glContext;
	delete _render;

	delete _releasePool;

	delete _timeScheduler;
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
GLContext* WorkingScope::getGLContext()
{
	return _glContext;
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

	setScene( createNode<TestScene>() );

	while( !glfwWindowShouldClose( _glContext->getWindow() ) )
	{
		_timeScheduler->onMainTick( calcDeltaTime() );
		drawScene();
		loopWait();
	}
}
