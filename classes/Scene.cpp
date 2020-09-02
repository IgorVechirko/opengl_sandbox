#include "Scene.h"


#include "Camera.h"
#include "DirectLightSource.h"
#include "PointLightSource.h"
#include "Flashlight.h"
#include "ShaderProgram.h"

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
		Node::visit( render, parentTransform );

		auto transform = parentTransform * getTransform();
		visitProtectedChilds( render, transform );
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
	void Scene::setProjectionToShader( ShaderProgram* shader )
	{
		if ( shader )
			shader->setUniformMatrix4fv( "u_projection", 1, false, glm::value_ptr( getCamera()->getProjection() ) );
	}
	void Scene::setViewToShader( ShaderProgram* shader )
	{
		if ( shader )
			shader->setUniformMatrix4fv( "u_view", 1, false, glm::value_ptr( getCamera()->getView() ) );
	}
	void Scene::setCameraPosToShader( ShaderProgram* shader )
	{
		if ( shader )
		{
			auto& cameraPos = getCamera()->getPosition();
			shader->setUniform3f( "u_cameraPos", cameraPos.x, cameraPos.y, cameraPos.z );
		}
	}
	void Scene::setDirectLightPropToShader( ShaderProgram* shader )
	{
		if ( shader && _directionLight )
		{
			LightProperties lightProperties = _directionLight->getLightProperties();
			glm::vec3 lightDirection = _directionLight->getDirection();

			shader->setLightPropUniforms( lightProperties, "u_directLight", "ambient", "diffuse", "specular" );
			shader->setUniform3f( "u_directLight.direction", lightDirection.x, lightDirection.y, lightDirection.z );
		}
	}
	void Scene::setPointLightsPropToShader( ShaderProgram* shader )
	{
		if ( shader )
		{
			shader->setUniform1i( "u_pointLightsCount", _pointLights.size() );

			for( int lightIndx = 0; lightIndx < _pointLights.size(); lightIndx++ )
			{
				const auto& light = _pointLights[lightIndx];
				const auto& lightPos = light->getPosition();

				shader->setLightPropUniforms( light->getLightProperties(), "u_pointLights[" + std::to_string(lightIndx) + "]", "ambient", "diffuse", "specular" );
				shader->setAttenuationCoefsUniforms( light->getAttenuation(), "u_pointLights[" + std::to_string(lightIndx) + "]", "constant", "linear", "quadratic" );
				shader->setUniform3f( "u_pointLights[" + std::to_string(lightIndx) + "].pos", lightPos.x, lightPos.y, lightPos.z );
			}
		}
	}
	void Scene::setFlashLightsPropToShader( ShaderProgram* shader )
	{
		if ( shader )
		{
			shader->setUniform1i( "u_flashlightsCount", _flashlights.size() );

			for( int lightIndx = 0; lightIndx < _flashlights.size(); lightIndx++ )
			{
				const auto& light = _flashlights[lightIndx];
				const auto& lightPos = light->getPosition();
				const auto& lightDirection = light->getDirection();

				shader->setLightPropUniforms( light->getLightProperties(), "u_flashlights[" + std::to_string(lightIndx) + "]", "ambient", "diffuse", "specular" );
				shader->setAttenuationCoefsUniforms( light->getAttenuation(), "u_flashlights[" + std::to_string(lightIndx) + "]", "constant", "linear", "quadratic" );
				shader->setUniform3f( "u_flashlights[" + std::to_string(lightIndx) + "].pos", lightPos.x, lightPos.y, lightPos.z );

				shader->setUniform3f( "u_flashlights[" + std::to_string(lightIndx) + "].direction", lightDirection.x, lightDirection.y, lightDirection.z );
				shader->setUniform1f( "u_flashlights[" + std::to_string(lightIndx) + "].cutOffAngleCos", glm::cos(glm::radians(light->getCutOffAngle())) );
				shader->setUniform1f( "u_flashlights[" + std::to_string(lightIndx) + "].outerCutOffAngleCos", glm::cos(glm::radians(light->getOuterCutOffAngle())) );
			}
		}
	}

}