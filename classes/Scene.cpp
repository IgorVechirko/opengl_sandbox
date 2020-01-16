#include "Scene.h"


#include "Camera.h"
#include "DirectLightSource.h"

_USEVE

Scene::Scene()
	: _directionLight( nullptr )
	, _camera( nullptr )
{
}
Scene::~Scene()
{
	if ( _directionLight )
	{
		_directionLight->release();
		_directionLight = nullptr;
	}
}
bool Scene::init()
{
	setCamera( Camera::create() );

	return true;
}
void Scene::visit( GLRender* render )
{
	Node::visit( render, Mat4(1.0f) );
}
void Scene::setDirectionLight( DirectLightSource* directionLight )
{
	if ( _directionLight != directionLight )
	{
		if ( _directionLight )
		{
			_directionLight->release();
			_directionLight = nullptr;
		}

		_directionLight = directionLight;

		if ( _directionLight )
		{
			_directionLight->retain();
		}
	}
}
DirectLightSource* Scene::getDirectionLight()
{
	return _directionLight;
}
void Scene::setCamera( Camera* camera )
{
	if ( camera && _camera != camera )
	{
		auto oldCamera = _camera;

		addChild( camera );
		_camera = camera;

		if ( oldCamera )
		{
			removeChild( oldCamera );
		}
	}
}
Camera* Scene::getCamera()
{
	return _camera;
}