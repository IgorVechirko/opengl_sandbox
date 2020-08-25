#ifndef WorkingScopeProvider_H
#define WorkingScopeProvider_H

#include "VECommon.h"

_VESTART

class WorkingScope;
class GLView;
class GLRender;
class FileUtils;
class ResourcesManager;
class AutoReleasePool;
class TimeScheduler;
class InputController;
class Scene;
class WorkingScopeProvider
{
	WorkingScope* _providedScope;

public:

	WorkingScopeProvider();
	WorkingScopeProvider( WorkingScope* scope );
	virtual ~WorkingScopeProvider();

	void setScope( WorkingScope* scope );
	WorkingScope* getScope();

	GLView* getGLView();
	GLRender* getRender();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	InputController* getInputController();

};


_VEEND



#endif