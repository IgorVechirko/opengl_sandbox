#ifndef WorkingScope_H
#define WorkingScope_H


#include "VECommon.h"

#include <chrono>

_VESTART

class GLContext;
class FileUtils;
class ResourcesManager;
class AutoReleasePool;
class TimeScheduler;
class WorkingScope
{
	GLContext* _glContext;

	FileUtils* _fileUtils;
	ResourcesManager* _resMng;

	AutoReleasePool* _releasePool;

	TimeScheduler* _timeScheduler;

	std::chrono::time_point<std::chrono::steady_clock> _lastUpdateTime;


	float calcDeltaTime();

	void loopWait();

public:

	WorkingScope();
	virtual ~WorkingScope();

	GLContext* getGLContext();

	FileUtils* getFileUtils();
	ResourcesManager* getResMng();

	AutoReleasePool* getReleasePool();

	TimeScheduler* getTimeScheduler();

	void startWork();



	template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
	ObjType* createObjWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			if( initializer )
			{
				if ( !(ret->*initializer)( initArgs...) )
				{
					delete ret;
					ret = nullptr;
				}
			}
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template<typename ObjType>
	ObjType* createScoped()
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->setScope( this );
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
	ObjType* createScopedWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->setScope( this );

			if( initializer )
			{
				if ( !(ret->*initializer)( initArgs...) )
				{
					delete ret;
					ret = nullptr;
				}
			}
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template<typename ObjType>
	ObjType* createRef()
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->autorelease( getReleasePool() );
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
	ObjType* createRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->autorelease( getReleasePool() );

			if( initializer )
			{
				if ( !(ret->*initializer)( initArgs...) )
				{
					delete ret;
					ret = nullptr;
				}
			}
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template< typename ObjType >
	ObjType* createScopedRef()
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->autorelease(getReleasePool());
			ret->setScope( this );
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}

	template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
	ObjType* createScopedRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
	{
		ObjType* result = new(std::nothrow) ObjType();

		if ( result )
		{
			result->autorelease(getReleasePool());
			result->setScope( this );

			if ( initializer )
			{
				if ( !(result->*initializer)( initArgs... ) )
				{
					delete result;
					result = nullptr;
				}
			}
		}
		else
		{
			delete result;
			result = nullptr;
		}

		return result;
	}

	template< typename ObjType >
	ObjType* createNode()
	{
		ObjType* ret = new(std::nothrow) ObjType();

		if ( ret )
		{
			ret->autorelease(getReleasePool());
			ret->setScope( this );

			if ( !ret->init() )
			{
				delete ret;
				ret = nullptr;
			}
		}
		else
		{
			delete ret;
			ret = nullptr;
		}

		return ret;
	}
};


_VEEND

#endif