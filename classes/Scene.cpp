#include "Scene.h"


#include "Camera.h"
#include "DirectLightSource.h"
#include "PointLightSource.h"
#include "Flashlight.h"

namespace GLSandbox
{

	Scene::Scene()
		: _directionLight( nullptr )
		, _camera( nullptr )
		, _maxPointLights( 10 )
		, _maxFlashlights( 10 )
	{
	}
	Scene::~Scene()
	{
	}
	bool Scene::onInit()
	{
		setCamera( createNode<Camera>() );

		return true;
	}
	void Scene::visit( GLRender* render )
	{
		Node::visit( render, Mat4(1.0f) );
	}
	void Scene::setDirectionLight( DirectLightSource* directionLight )
	{
		if ( directionLight && _directionLight != directionLight )
		{
			addChild( directionLight );
		
			if ( _directionLight )
			{
				removeChild( _directionLight );
			}

			_directionLight = directionLight;
		}
	}
	DirectLightSource* Scene::getDirectionLight()
	{
		return _directionLight;
	}
	void Scene::addPointLight( PointLightSource* light )
	{
		if ( _pointLights.size() < _maxPointLights )
		{
			addChild( light );
			_pointLights.push_back( light );
		}
	}
	const std::vector<PointLightSource*>& Scene::getPointLights() const
	{
		return _pointLights;
	}
	void Scene::addFlashlight( Flashlight* light )
	{
		if ( _flashlights.size() < _maxFlashlights )
		{
			addChild( light );
			_flashlights.push_back( light );
		}
	}
	const std::vector<Flashlight*>& Scene::getFlashLights() const
	{
		return _flashlights;
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

}