#ifndef GLRender_H
#define GLRender_H

#include "VECommon.h"

_VESTART

class LightSource;
class Scene;
class GLRender
{


	LightSource* _lightSource;

public:

	GLRender();
	virtual ~GLRender();

	void init();

	void drawScene( Scene* scene );

	void setLightSource( LightSource* source );
	LightSource* getLightSource();
};

_VEEND

#endif