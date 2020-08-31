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
	void Scene::visit( GLRender* render, const Mat4& parentTransform )
	{
		visitProtectedChilds( render, parentTransform );

		Node::visit( render, parentTransform );
	}
	void Scene::setDirectionLight( DirectLightSource* directionLight )
	{
		if ( _directionLight != directionLight )
		{
			if ( _directionLight )
				removeProtectedChild( _directionLight );

			if ( directionLight )
				addProtectedChild( directionLight );

			_directionLight = directionLight;
		}
	}
	DirectLightSource* Scene::getDirectionLight()
	{
		return _directionLight;
	}
	void Scene::addPointLight( PointLightSource* light )
	{
		if ( light && _pointLights.size() < _maxPointLights )
		{
			addProtectedChild( light );
			_pointLights.push_back( light );
		}
	}
	const std::vector<PointLightSource*>& Scene::getPointLights() const
	{
		return _pointLights;
	}
	void Scene::addFlashlight( Flashlight* light )
	{
		if ( light && _flashlights.size() < _maxFlashlights )
		{
			addProtectedChild( light );
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
			if ( _camera )
				removeProtectedChild( _camera );

			addProtectedChild( camera );

			_camera = camera;
		}
	}
	Camera* Scene::getCamera()
	{
		_ASSERT( _camera );
		return _camera;
	}

}