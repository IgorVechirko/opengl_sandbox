#ifdef BUILD

#include "WorkingScope.h"
#include "TestScopeDelegat.h"

int main()
{
	GLSandbox::WorkingScope scope;
	auto scopeDelegate = std::shared_ptr<TestScopeDelegat>(scope.createScoped<TestScopeDelegat>());
	scope.startWithDelegate( scopeDelegate.get() );

    return 0;
}
#endif