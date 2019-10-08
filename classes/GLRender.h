#ifndef GLRender_H
#define GLRender_H

#include "VECommon.h"

_VESTART

class Scene;
class GLRender
{

public:

	GLRender();
	virtual ~GLRender();

	void init();

	void drawScene( Scene* scene );
};

_VEEND

#endif