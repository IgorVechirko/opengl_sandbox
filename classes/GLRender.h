#ifndef GLRender_H
#define GLRender_H

#include "WorkingScopeProvider.h"

_VESTART

class Scene;
class GLRender : public WorkingScopeProvider
{

public:

	GLRender( WorkingScope* scope );
	virtual ~GLRender();

	void init();

	void drawScene( Scene* scene );
};

_VEEND

#endif