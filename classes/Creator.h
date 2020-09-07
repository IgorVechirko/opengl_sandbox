#ifndef Creator_H
#define Creator_H

#include "Allocator.h"


namespace GLSandbox
{
	class WorkingScope;
	class Creator
	{

		WorkingScope* _scope;
		Allocator _allocator;


	public:

		Creator();
		virtual ~Creator();
		MAKE_UNCOPYABLE(Creator);

		void setScope( WorkingScope* scope );
		WorkingScope* getScope();

		template< typename ObjType, typename... Types >
		ObjType* createObj( const Types&... constructArgs )
		{
			ObjType* ret = new(_allocator.allocate(sizeof(ObjType))) ObjType( constructArgs... );
			return ret;
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createObjWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				if ( !(ret->*initializer)( initArgs...) )
				{
					_allocator.deallocate( ret );
					ret = nullptr;
				}
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template<typename ObjType>
		ObjType* createScoped()
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setScope( getScope() );
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setScope( getScope() );

				if ( !(ret->*initializer)( initArgs...) )
				{
					_allocator.deallocate( ret );
					ret = nullptr;
				}
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template<typename ObjType>
		ObjType* createRef()
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setupReleasePool( _scope->getReleasePool() );
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret && (ret->*initializer)( initArgs...) )
			{
				ret->setupReleasePool( _scope->getReleasePool() );
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template< typename ObjType >
		ObjType* createScopedRef()
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setupReleasePool(_scope->getReleasePool());
				ret->setScope( getScope() );
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template< typename ObjType, typename InitializerType, typename... InitArgsTypes > 
		ObjType* createScopedRefWithInitializer( InitializerType initializer, const InitArgsTypes&... initArgs )
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setScope( getScope() );

				if ( (ret->*initializer)( initArgs... ) )
				{
					ret->setupReleasePool(_scope->getReleasePool());
				}
				else
				{
					_allocator.deallocate( ret );
					ret = nullptr;
				}
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template< typename ObjType >
		ObjType* createNode()
		{
			ObjType* ret = createObj<ObjType>();

			if ( ret )
			{
				ret->setScope( getScope() );

				if ( ret->init() )
				{
					ret->setupReleasePool(_scope->getReleasePool());
				}
				else
				{
					_allocator.deallocate( ret );
					ret = nullptr;
				}
			}
			else
			{
				_allocator.deallocate( ret );
				ret = nullptr;
			}

			return ret;
		}

		template<typename ObjType>
		void destroyObj( ObjType* ptr )
		{
			ptr->~ObjType();
			_allocator.deallocate(ptr);
		}


	};

}


#endif 