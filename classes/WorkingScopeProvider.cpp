#include "WorkingScopeProvider.h"

#include "WorkingScope.h"
#include <assert.h>
_USEVE

WorkingScopeProvider::WorkingScopeProvider()
	: _providedScope( nullptr )
{

}
WorkingScopeProvider::WorkingScopeProvider( WorkingScope* scope )
	: _providedScope( scope )
{

}
WorkingScopeProvider::~WorkingScopeProvider()
{
}
void WorkingScopeProvider::setScope( WorkingScope* scope )
{
	_providedScope = scope;
}
WorkingScope* WorkingScopeProvider::getScope()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope;
}
GLView* WorkingScopeProvider::getGLView()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getGLView();
}
GLRender* WorkingScopeProvider::getRender()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getRender();
}
FileUtils* WorkingScopeProvider::getFileUtils()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getFileUtils();
}
ResourcesManager* WorkingScopeProvider::getResMng()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getResMng();
}
AutoReleasePool* WorkingScopeProvider::getReleasePool()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getReleasePool();
}
TimeScheduler* WorkingScopeProvider::getTimeScheduler()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getTimeScheduler();
}
InputController* WorkingScopeProvider::getInputController()
{
	_ASSERT( _providedScope != nullptr );
	return _providedScope->getInputController();
}