#ifndef WorkingScope_H
#define WorkingScope_H

#include "VECommon.h"

#include <chrono>

_VESTART


class GLView;
class GLRender;
class FileUtils;
class ResourcesManager;
class AutoReleasePool;
class TimeScheduler;
class InputController;
class Scene;
class WorkingScope
{

	GLView* _view;
	GLRender* _render;

	FileUtils* _fileUtils;
	ResourcesManager* _resMng;

	AutoReleasePool* _releasePool;

	TimeScheduler* _timeScheduler;

	InputController* _inputController;

	Scene* _scene;

	std::chrono::time_point<std::chrono::steady_clock> _lastUpdateTime;



	void drawScene();

	float calcDeltaTime();

	void loopWait();

public:

	WorkingScope();
	virtual ~WorkingScope();

	GLView* getView();
	GLRender* getRender();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	InputController* getInputController();

	void setScene( Scene* scene );
	Scene* getScene();

	void startWork();

};


_VEEND

#endif