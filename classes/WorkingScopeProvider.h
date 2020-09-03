#ifndef WorkingScopeProvider_H
#define WorkingScopeProvider_H

#include "WorkingScope.h"

namespace GLSandbox
{

	class FileUtils;
	class ResourcesManager;
	class AutoReleasePool;
	class TimeScheduler;
	class GLContext;
	class WorkingScope;
	class Creator;
	class TexturesCache;
	class WorkingScopeProvider
	{
		TEST_FRIEND

		WorkingScope* _providedScope;

	public:

		WorkingScopeProvider();
		WorkingScopeProvider( WorkingScope* scope );
		virtual ~WorkingScopeProvider();

		void setScope( WorkingScope* scope );
		WorkingScope* getScope();

		GLContext* getGLContext();
	
		FileUtils* getFileUtils();
		ResourcesManager* getResMng();

		AutoReleasePool* getReleasePool();

		TimeScheduler* getTimeScheduler();

		TexturesCache* getTexturesCache();

		Creator* getCreator();


		template< typename ObjType, typename... Types >
		ObjType* createObj( const Types&... constructArgs )
		{
			_ASSERT(_providedScope);

			return _providedScope->createObj<ObjType>(constructArgs...);
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createObjWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			_ASSERT(_providedScope);

			return _providedScope->createScopedWithInitializer<ObjType>(initializer, initArgs... );
		}

		template<typename ObjType>
		ObjType* createScoped()
		{
			_ASSERT(_providedScope);

			return _providedScope->createScoped<ObjType>();
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			_ASSERT(_providedScope);

			return _providedScope->createScopedWithInitializer<ObjType>(initializer, initArgs... );
		}

		template<typename ObjType>
		ObjType* createRef()
		{
			_ASSERT(_providedScope);

			return _providedScope->createRef<ObjType>();
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			_ASSERT(_providedScope);

			return _providedScope->createRefWithInitializer<ObjType>(initializer, initArgs... );
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			_ASSERT(_providedScope);

			return _providedScope->createScopedRefWithInitializer<ObjType>(initializer, initArgs... );
		}

		template< typename ObjType >
		ObjType* createNode()
		{
			_ASSERT(_providedScope);

			return _providedScope->createNode<ObjType>();
		}

		template<typename ObjType>
		void destoryObj( ObjType* ptr )
		{
			_providedScope->destroyObj( ptr );
		}

	};

}



#endif