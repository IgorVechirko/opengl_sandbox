#ifndef Scene_H
#define Scene_H

#include "Node.h"

_VESTART

class GLRender;
class DirectLightSource;
class Scene : public Node
{

	DirectLightSource* _directionLight;


protected:

	Scene();

public:

	virtual ~Scene();

	CREATE_FUNC(Scene);

	void visit( GLRender* render );

	void setDirectionLight( DirectLightSource* directionLight );
	DirectLightSource* getDirectionLight();

};

_VEEND

#endif