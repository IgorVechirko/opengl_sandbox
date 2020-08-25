#ifndef Scene_H
#define Scene_H

#include "Node.h"

_VESTART

class Camera;
class DirectLightSource;
class PointLightSource;
class Flashlight;
class Scene : public Node
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

	void visit( GLRender* render );

	void setDirectionLight( DirectLightSource* directionLight );
	DirectLightSource* getDirectionLight();

	void addPointLight( PointLightSource* light );
	const std::vector<PointLightSource*> getPointLights();

	void addFlashlight( Flashlight* light );
	const std::vector<Flashlight*>& getFlashLights();

	void setCamera( Camera* camera );
	Camera* getCamera();

};

_VEEND

#endif