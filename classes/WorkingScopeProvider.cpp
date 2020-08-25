#include "WorkingScopeProvider.h"

#include "WorkingScope.h"

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
	return _providedScope;
}
GLView* WorkingScopeProvider::getView()
{
	if ( _providedScope )
		return _providedScope->getView();
	else 
		return nullptr;
}
GLRender* WorkingScopeProvider::getRender()
{
	if ( _providedScope )
		return _providedScope->getRender();
	else 
		return nullptr;
}
FileUtils* WorkingScopeProvider::getFileUtils()
{
	if ( _providedScope )
		return _providedScope->getFileUtils();
	else 
		return nullptr;
}
ResourcesManager* WorkingScopeProvider::getResMng()
{
	if ( _providedScope )
		return _providedScope->getResMng();
	else 
		return nullptr;
}
AutoReleasePool* WorkingScopeProvider::getReleasePool()
{
	if ( _providedScope )
		return _providedScope->getReleasePool();
	else 
		return nullptr;
}
TimeScheduler* WorkingScopeProvider::getTimeScheduler()
{
	if ( _providedScope )
		return _providedScope->getTimeScheduler();
	else 
		return nullptr;
}
InputController* WorkingScopeProvider::getInputController()
{
	if ( _providedScope )
		return _providedScope->getInputController();
	else 
		return nullptr;
}