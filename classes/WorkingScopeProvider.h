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
class WorkingScopeProvider
{
	WorkingScope* _providedScope;

public:

	WorkingScopeProvider();
	WorkingScopeProvider( WorkingScope* scope );
	virtual ~WorkingScopeProvider();

	void setScope( WorkingScope* scope );
	WorkingScope* getScope();

	GLView* getView();
	GLRender* getRender();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	InputController* getInputController();

};


#define VIEW getView()
#define RENDER getRender()
#define FILE_UTILS getFileUtils()
#define RES_MNG getResMng()
#define RELEASE_POOL getReleasePool()
#define SCHEDULER getTimeScheduler()
#define RES_PATH(__RES_ID__) getResMng()->getResPath(__RES_ID__)
#define INPUT getInputController()
#define CUR_SCENE getScope()->getScene()
#define CAMERA CUR_SCENE->getCamera()



_VEEND



#endif