#include "WorkingScope.h"

#include "WorkingScope.h"
#include "FileUtils.h"
#include "ResourcesManager.h"
#include "AutoReleasePool.h"
#include "TimeScheduler.h"
#include "GLContext.h"
#include "ScopeDelegate.h"
#include "Creator.h"
#include "TexturesCache.h"
#include "ShadersCache.h"

namespace GLSandbox
{

	WorkingScope::WorkingScope()
		: _glContext( nullptr )
		, _fileUtils( nullptr )
		, _resMng( nullptr )
		, _releasePool( nullptr )
		, _timeScheduler( nullptr )
		, _delegate( nullptr )
		, _texturesCache( nullptr )
		, _shadersCache( nullptr )
	{
		_creator.setScope( this );

		_releasePool = std::unique_ptr<AutoReleasePool>(new AutoReleasePool);
		_releasePool->setScope( this );

		_fileUtils = std::unique_ptr<FileUtils>(new FileUtils);
		_fileUtils->setScope( this );

		_resMng = std::unique_ptr<ResourcesManager>(new ResourcesManager);
		_resMng->setScope( this );

		_glContext = _creator.createScopedWithInitializer<GLContext>(&GLContext::initWithWndSize, 1024, 768 );

		_timeScheduler = std::unique_ptr<TimeScheduler>(new TimeScheduler);
		_timeScheduler->setScope( this );

		_texturesCache = std::unique_ptr<TexturesCache>( new TexturesCache);
		_texturesCache->setScope( this );

		_shadersCache = std::unique_ptr<ShadersCache>( new ShadersCache);
		_shadersCache->setScope( this );

	}
	WorkingScope::~WorkingScope()
	{
		destroyObj( _glContext );
	}
	GLContext* WorkingScope::getGLContext()
	{
		_ASSERT( _glContext );
		return _glContext;
	}
	FileUtils* WorkingScope::getFileUtils()
	{
		_ASSERT( _fileUtils.get() );
		return _fileUtils.get();
	}
	ResourcesManager* WorkingScope::getResMng()
	{
		_ASSERT( _resMng.get() );
		return _resMng.get();
	}
	AutoReleasePool* WorkingScope::getReleasePool()
	{
		_ASSERT( _releasePool.get() );
		return _releasePool.get();
	}
	TimeScheduler* WorkingScope::getTimeScheduler()
	{
		_ASSERT( _timeScheduler.get() );
		return _timeScheduler.get();
	}
	TexturesCache* WorkingScope::getTexturesCache()
	{
		_ASSERT( _texturesCache.get() );
		return _texturesCache.get();
	}
	ShadersCache* WorkingScope::getShadersCache()
	{
		_ASSERT( _shadersCache.get() );
		return _shadersCache.get();
	}
	Creator* WorkingScope::getCreator()
	{
		return &_creator;
	}
	void WorkingScope::startWithDelegate( ScopeDelegate* delegate )
	{
		_texturesCache->init();
		_shadersCache->init();

		_glContext->setScene( createNode<Scene>() );

		if ( delegate )
		{
			_delegate = delegate;
		}
		else
		{
			_defaultDelegate = std::unique_ptr<ScopeDelegate>(createScoped<ScopeDelegate>());
			_delegate = _defaultDelegate.get();
		}

		_delegate->setScope( this );
		_delegate->init();

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
