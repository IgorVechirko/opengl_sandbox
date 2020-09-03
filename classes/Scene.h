#ifndef Scene_H
#define Scene_H

#include "Node.h"
#include "NodeExtensions.h"

namespace GLSandbox
{

	class Camera;
	class DirectLightSource;
	class PointLightSource;
	class Flashlight;
	class Scene 
		: public Node
		, public ProtectedChildrenProtocol
	{
		typedef Node Parent;

		Camera* _camera;

		DirectLightSource* _directionLight;
	
		const int _maxPointLights;
		std::vector<PointLightSource*> _pointLights;

		const int _maxFlashlights;
		std::vector<Flashlight*> _flashlights;


	protected:

		virtual bool onInit() override;

	public:

		Scene();
		virtual ~Scene();

		virtual void drawTraversal( const Mat4& parentTransform ) override;

		void setDirectionLight( DirectLightSource* directionLight );
		DirectLightSource* getDirectionLight();

		void addPointLight( PointLightSource* light );
		const std::vector<PointLightSource*>& getPointLights() const;

		void addFlashlight( Flashlight* light );
		const std::vector<Flashlight*>& getFlashLights() const;

		void setCamera( Camera* camera );
		Camera* getCamera();

		void setProjectionToShader( ShaderProgram* shader );
		void setViewToShader( ShaderProgram* shader );
		void setCameraPosToShader( ShaderProgram* shader );
		void setDirectLightPropToShader( ShaderProgram* shader );
		void setPointLightsPropToShader( ShaderProgram* shader );
		void setFlashLightsPropToShader( ShaderProgram* shader );

	};

}

#endif