#include "Scene.h"

#include "Director.h"


#include "DirectLightSource.h"

_USEVE

Scene::Scene()
	: _directionLight( nullptr )
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