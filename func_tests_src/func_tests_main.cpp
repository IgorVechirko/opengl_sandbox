#include "WorkingScope.h"
#include "TestScopeDelegat.h"

using namespace GLSandbox;
using namespace WorkingTests;

int main()
{
	WorkingScope scope;
	auto scopeDelegate = scope.createScoped<TestScopeDelegat>();
	scope.startWithDelegate( scopeDelegate );
	scope.destroyObj(scopeDelegate);

    return 0;
}