#ifndef WorkingScope_H
#define WorkingScope_H


#include "Common.h"
#include "Creator.h"

namespace GLSandbox
{

	class GLContext;
	class FileUtils;
	class ResourcesManager;
	class AutoReleasePool;
	class TimeScheduler;
	class ScopeDelegate;
	class Creator;
	class TexturesCache;
	class WorkingScope
	{
		Creator _creator;

		std::shared_ptr<AutoReleasePool> _releasePool;

		GLContext* _glContext;

		std::shared_ptr<FileUtils> _fileUtils;
		std::shared_ptr<ResourcesManager> _resMng;

		std::shared_ptr<TimeScheduler> _timeScheduler;

		std::shared_ptr<TexturesCache> _texturesCache;

		ScopeDelegate* _delegate;
		std::shared_ptr<ScopeDelegate> _defaultDelegate;

	public:

		WorkingScope();
		MAKE_UNCOPYABLE( WorkingScope );
	
		virtual ~WorkingScope();

		GLContext* getGLContext();

		FileUtils* getFileUtils();
		ResourcesManager* getResMng();

		AutoReleasePool* getReleasePool();

		TimeScheduler* getTimeScheduler();

		TexturesCache* getTexturesCache();

		Creator* getCreator();

		void startWithDelegate( ScopeDelegate* delegate );


		template< typename ObjType, typename... Types >
		ObjType* createObj( const Types&... constructArgs )
		{
			return _creator.createObj<ObjType>( constructArgs... );
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createObjWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			return _creator.createObjWithInitializer<ObjType>(initializer, initArgs... );
		}

		template<typename ObjType>
		ObjType* createScoped()
		{
			return _creator.createScoped<ObjType>();
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			return _creator.createScopedWithInitializer<ObjType>( initializer, initArgs...);
		}

		template<typename ObjType>
		ObjType* createRef()
		{
			return _creator.createRef<ObjType>();
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			return _creator.createRefWithInitializer<ObjType>(initializer, initArgs...);
		}

		template< typename ObjType >
		ObjType* createScopedRef()
		{
			return _creator.createScopedRef<ObjType>();
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			return _creator.createScopedRefWithInitializer<ObjType>(initializer, initArgs...);
		}

		template< typename ObjType >
		ObjType* createNode()
		{
			return _creator.createNode<ObjType>();
		}

		template<typename ObjType>
		void destroyObj( ObjType* ptr )
		{
			_creator.destroyObj( ptr );
		}
	};


}

#endif