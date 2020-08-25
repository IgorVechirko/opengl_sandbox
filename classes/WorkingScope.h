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

	GLView* getGLView();
	GLRender* getRender();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	InputController* getInputController();

	void setScene( Scene* scene );
	Scene* getScene();

	void startWork();

	template< typename T, typename InitializerType, typename... InitArgsTypes > 
	T* createScopedWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
	{
		T* result = new(std::nothrow) T();

		if ( result )
		{
			result->setScope( this );

			if ( !(result->*initializer)( initArgs... ) )
			{
				delete result;
				result = nullptr;
			}
		}
		else
		{
			delete result;
			result = nullptr;
		}

		return result;
	}
};


_VEEND

#endif