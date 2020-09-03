#include "WorkingScope.h"
#include "TestScopeDelegat.h"
#include "FunctionalTestsDelegate.h"

using namespace GLSandbox;
using namespace FuncTests;

int main()
{
	WorkingScope scope;
	auto scopeDelegate = scope.createScoped<FunctionalTestsDelegate>();
	scope.startWithDelegate( scopeDelegate );
	scope.destroyObj(scopeDelegate);

    return 0;
}