#ifndef Application_H
#define Application_H

#include "VECommon.h"

_VESTART

class Application
{

	Application();

protected:

	virtual void initView();
	virtual void initContent();


public:

	virtual ~Application();

	static Application* getInstance();

	int run();
};

_VEEND

#endif