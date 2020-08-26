#include "RefTest.h"

#include <boost/test/unit_test.hpp>

#define TEST_FRIEND friend UnitTests::RefTest;
#include "Ref.h"

namespace UnitTests
{

	void RefTest::membersInit()
	{
		VEngine::Ref ref;

		BOOST_TEST( ref._refCount == 0, "_refCout wrong init" );
		BOOST_TEST( ref._autorelesed == false, "_autorelesed wrong init" );
		BOOST_TEST( ref._pool == nullptr, "_pool wrong init" );
	}

	void RefTest::retainMethodWork()
	{
		VEngine::Ref ref;
		ref.retain();

		BOOST_TEST( ref._refCount == 1, "wron single retain" );


		VEngine::Ref ref2;
		for( int i = 0; i < 10; i++ )
			ref2.retain();

		BOOST_TEST( ref2._refCount == 10, "wrong few retains" );
	}

	void RefTest::releaseMethodWork()
	{
		VEngine::Ref ref;
		ref._refCount = 12;
		ref.release();

		BOOST_TEST( ref._refCount == 11, "wrong single release" );


		VEngine::Ref ref2;
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