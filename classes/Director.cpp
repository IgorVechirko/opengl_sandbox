#include "Director.h"

_USEVE


Director::Director()
	: _view( nullptr )
	, _render( nullptr )
	, _camera( nullptr )
	, _fileUtils( nullptr )
	, _resMng( nullptr )
	, _scene( nullptr )
	, _releasePool( nullptr )
{
	_fileUtils = new FileUtils();
	_resMng = new ResourcesManager();

	_view = new GLView();
	_render = new GLRender();

	_releasePool = new AutoReleasePool();
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
}
void Director::drawScene()
{
	_releasePool->chechPool();

	RENDER->drawScene( _scene );
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