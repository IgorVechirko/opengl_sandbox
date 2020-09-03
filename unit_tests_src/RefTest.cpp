#include "RefTest.h"

#include <boost/test/unit_test.hpp>

#define TEST_FRIEND friend UnitTests::RefTest;
#include "Ref.h"

namespace UnitTests
{

	void RefTest::membersInit()
	{
		GLSandbox::Ref ref;

		BOOST_TEST( ref._refCount == 0, "_refCout wrong init" );
		BOOST_TEST( ref._pool == nullptr, "_pool wrong init" );
	}

	void RefTest::retainMethodWork()
	{
		GLSandbox::Ref ref;
		ref.retain();

		BOOST_TEST( ref._refCount == 1, "wron single retain" );


		GLSandbox::Ref ref2;
		for( int i = 0; i < 10; i++ )
			ref2.retain();

		BOOST_TEST( ref2._refCount == 10, "wrong few retains" );
	}

	void RefTest::releaseMethodWork()
	{
		GLSandbox::Ref ref;
		ref._refCount = 12;
		ref.release();

		BOOST_TEST( ref._refCount == 11, "wrong single release" );


		GLSandbox::Ref ref2;
		ref2._refCount = 12;
		for( int i = 0 ; i < 10; i++ )
			ref2.release();

		BOOST_TEST( ref2._refCount == 2, "wrong few releases" );

	}

}


BOOST_AUTO_TEST_SUITE( RefTestSuite )

BOOST_AUTO_TEST_CASE( membersInit )
{
	UnitTests::RefTest::membersInit();
}

BOOST_AUTO_TEST_CASE( retainMethodWork )
{
	UnitTests::RefTest::retainMethodWork();
}

BOOST_AUTO_TEST_CASE( releaseMethodWork )
{
	UnitTests::RefTest::releaseMethodWork();
}
BOOST_AUTO_TEST_SUITE_END()