#ifndef Scene_H
#define Scene_H

#include "Node.h"

_VESTART

class Camera;
class DirectLightSource;
class Scene : public Node
{
	typedef Node Parent;

	Camera* _camera;

	DirectLightSource* _directionLight;


protected:

	Scene();

	virtual bool init() override;

public:

	virtual ~Scene();

	CREATE_FUNC(Scene);

	void visit( GLRender* render );

	void setDirectionLight( DirectLightSource* directionLight );
	DirectLightSource* getDirectionLight();

	void setCamera( Camera* camera );
	Camera* getCamera();

};

_VEEND

#endif