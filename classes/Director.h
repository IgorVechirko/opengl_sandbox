#ifndef Director_H
#define Director_H

#include "GLView.h"
#include "GLRender.h"
#include "Camera.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "Scene.h"
#include "AutoReleasePool.h"
#include "TimeScheduler.h"
#include "InputController.h"

#include <chrono>

_VESTART

class Application;
class Director
{

	GLView* _view;
	GLRender* _render;
	Camera* _camera;

	FileUtils* _fileUtils;
	ResourcesManager* _resMng;

	AutoReleasePool* _releasePool;

	TimeScheduler* _timeScheduler;

	InputController* _inputController;

	Scene* _scene;


	std::chrono::time_point<std::chrono::steady_clock> _lastUpdateTime;

	Director();

	void drawScene();

	float calcDeltaTime();

	void loopWait();

public:

	virtual ~Director();

	static Director* getInstance(); 

	void init();

	void runMainLoop();

	void setView( GLView* view );
	GLView* getView();

	GLRender* getRender();

	void setCamera( Camera* camera );
	Camera* getCamera();
	
	void setScene( Scene* scene );
	Scene* getScene();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	InputController* getInputController();
};

#define VIEW Director::getInstance()->getView()
#define RENDER Director::getInstance()->getRender()
#define CAMERA Director::getInstance()->getCamera()
#define FILE_UTILS Director::getInstance()->getFileUtils()
#define RES_MNG Director::getInstance()->getResMng()
#define RELEASE_POOL Director::getInstance()->getReleasePool()
#define SCHEDULER Director::getInstance()->getTimeScheduler()
#define RES_PATH(__RES_ID__) Director::getInstance()->getResMng()->getResPath(__RES_ID__)
#define INPUT Director::getInstance()->getInputController()

_VEEND

#endif