#ifndef Director_H
#define Director_H

#include "GLView.h"
#include "GLRender.h"
#include "Camera.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "Scene.h"
#include "AutoReleasePool.h"

_VESTART

class Application;
class Director
{
	friend Application;

	GLView* _view;
	GLRender* _render;
	Camera* _camera;

	FileUtils* _fileUtils;
	ResourcesManager* _resMng;

	AutoReleasePool* _releasePool;

	Scene* _scene;

	Director();

	void drawScene();

public:

	virtual ~Director();

	static Director* getInstance(); 

	void init();

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
};

#define VIEW Director::getInstance()->getView()
#define RENDER Director::getInstance()->getRender()
#define CAMERA Director::getInstance()->getCamera()
#define FILE_UTILS Director::getInstance()->getFileUtils()
#define RES_MNG Director::getInstance()->getResMng()
#define RELEASE_POOL Director::getInstance()->getReleasePool()
#define RES_PATH(__RES_ID__) Director::getInstance()->getResMng()->getResPath(__RES_ID__)

_VEEND

#endif