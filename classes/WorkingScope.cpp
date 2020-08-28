#include "WorkingScope.h"

#include "WorkingScope.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "AutoReleasePool.h"
#include "TimeScheduler.h"
#include "GLContext.h"
#include "ScopeDelegate.h"

namespace GLSandbox
{

	WorkingScope::WorkingScope()
		: _glContext( nullptr )
		, _fileUtils( nullptr )
		, _resMng( nullptr )
		, _releasePool( nullptr )
		, _timeScheduler( nullptr )
		, _delegate( nullptr )
	{
		_fileUtils = new FileUtils(this);
		_resMng = new ResourcesManager(this);

		_glContext = createScopedWithInitializer<GLContext>(&GLContext::initWithWndSize, 1024, 768 );

		_releasePool = new AutoReleasePool(this);

		_timeScheduler = new TimeScheduler(this);
	}
	WorkingScope::~WorkingScope()
	{
		delete _fileUtils;
		delete _resMng;

		delete _glContext;

		delete _releasePool;

		delete _timeScheduler;
	}
	GLContext* WorkingScope::getGLContext()
	{
		_ASSERT( _glContext );
		return _glContext;
	}
	FileUtils* WorkingScope::getFileUtils()
	{
		_ASSERT( _fileUtils );
		return _fileUtils;
	}
	ResourcesManager* WorkingScope::getResMng()
	{
		_ASSERT( _resMng );
		return _resMng;
	}
	AutoReleasePool* WorkingScope::getReleasePool()
	{
		_ASSERT( _releasePool );
		return _releasePool;
	}
	TimeScheduler* WorkingScope::getTimeScheduler()
	{
		_ASSERT( _timeScheduler );
		return _timeScheduler;
	}
	void WorkingScope::startWithDelegate( ScopeDelegate* delegate )
	{
		if ( delegate )
		{
			_delegate = delegate;
		}
		else
		{
			_defaultDelegate = std::shared_ptr<ScopeDelegate>(createScoped<ScopeDelegate>());
			_delegate = _defaultDelegate.get();
		}

		_delegate->setScope( this );

		_resMng->init();

		_glContext->setScene( _delegate->getStartScene() );

		while( !_glContext->windowShouldClose() )
		{
			_timeScheduler->doMainTick();

			_releasePool->checkPool();

			_glContext->drawScene();

			_timeScheduler->doWaitFrameEnd();

			_glContext->poolEvents();
		}
	}

}
