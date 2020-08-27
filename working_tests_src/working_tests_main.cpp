#include "WorkingScope.h"
#include "TestScopeDelegat.h"

using namespace GLSandbox;
using namespace WorkingTests;

int main()
{
	WorkingScope scope;
	auto scopeDelegate = std::shared_ptr<TestScopeDelegat>(scope.createScoped<TestScopeDelegat>());
	scope.startWithDelegate( scopeDelegate.get() );

    return 0;
}