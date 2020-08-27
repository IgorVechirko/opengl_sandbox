#include "TimeSchedulerTest.h"

#include "boost/test/unit_test.hpp"

#define TEST_FRIEND friend UnitTests::TimeSchedulerTest;
#include "TimeScheduler.h"

namespace UnitTests
{

	void TimeSchedulerTest::membersInit()
	{

		VEngine::TimeScheduler scheduler(nullptr);

		BOOST_TEST( scheduler._providedScope == nullptr, "working scope wrong init" );

		BOOST_TEST( scheduler._updateFunctions.size() == 0, "_updateFunctions wrong init");
		
	}

	void TimeSchedulerTest::addUpdateFuncMethodWork()
	{
		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			} testObj;

			scheduler.addUpdateFunc( nullptr, &testObj );

			auto findIt = scheduler._updateFunctions.find( &testObj );
			auto result = ( findIt == scheduler._updateFunctions.end() );

			BOOST_TEST( result, "can add nullptr func" );
		}
		
		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			} testObj;

			scheduler.addUpdateFunc( std::bind(&SchedulerTest::update, &testObj, std::placeholders::_1  ), nullptr );;
			
			auto findIt = scheduler._updateFunctions.find( &testObj );
			auto result = ( findIt == scheduler._updateFunctions.end() );

			BOOST_TEST( result, "can add nullptr target" );
		}

		{
			VEngine::TimeScheduler scheduler(nullptr);
			scheduler.addUpdateFunc( nullptr, nullptr );

			auto findIt = scheduler._updateFunctions.find( nullptr );
			
			bool result = true;
			if ( findIt != scheduler._updateFunctions.end() )
			{
				if ( findIt->second == nullptr )
				{
					result = false;
				}
			}


			BOOST_TEST( result, "can add nullptr target and nullptr func" );
		}

		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			} testObj;

			scheduler.addUpdateFunc( std::bind( &SchedulerTest::update, &testObj, std::placeholders::_1 ), &testObj );

			auto findIt = scheduler._updateFunctions.find( &testObj );
			bool result = ( findIt != scheduler._updateFunctions.end() );

			BOOST_TEST( result, "wrong add single function" );
		}

		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			};

			std::vector<std::shared_ptr<SchedulerTest>> testObjs;
			int testedCasesAmount = 10;

			for( int i = 0; i < testedCasesAmount; i++ )
			{
				auto testObjShared = std::shared_ptr<SchedulerTest>( new SchedulerTest() );
				scheduler.addUpdateFunc( std::bind(&SchedulerTest::update, testObjShared.get(), std::placeholders::_1 ), testObjShared.get() );
				testObjs.push_back( testObjShared );
			}

			auto result = true;

			for( auto testObjShared : testObjs )
			{
				auto findIt = scheduler._updateFunctions.find( testObjShared.get() );

				if ( findIt == scheduler._updateFunctions.end() )
				{
					result = false;
					break;
				}
			}
			

			BOOST_TEST( result , "wrong add few functions");
		}

	}

	void TimeSchedulerTest::delUpdateFuncMethodWork()
	{
		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			} testObj;

			scheduler._updateFunctions[&testObj] = std::bind( &SchedulerTest::update, &testObj, std::placeholders::_1 );
			scheduler.delUpdateFunc( &testObj );

			auto findIt = scheduler._updateFunctions.find( &testObj );
			bool result = ( findIt == scheduler._updateFunctions.end() );

			BOOST_TEST( result, "wrong del single function" );
		}

		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				void update( float deltaTime ){};
			};

			std::vector<std::shared_ptr<SchedulerTest>> testObjs;
			int testedCasesAmount = 10;

			for( int i = 0; i < testedCasesAmount; i++ )
			{
				auto testObjShared = std::shared_ptr<SchedulerTest>( new SchedulerTest() );
				scheduler._updateFunctions[testObjShared.get()] = std::bind(&SchedulerTest::update, testObjShared.get(), std::placeholders::_1 );
				testObjs.push_back( testObjShared );
			}

			for( auto testObjShared : testObjs )
			{
				scheduler.delUpdateFunc( testObjShared.get() );
			}

			auto result = true;

			for( auto testObjShared : testObjs )
			{
				auto findIt = scheduler._updateFunctions.find( testObjShared.get() );

				if ( findIt != scheduler._updateFunctions.end() )
				{
					result = false;
					break;
				}
			}
			

			BOOST_TEST( result , "wrong del few functions");
		}
	}

	void TimeSchedulerTest::doMainTickMethodWork()
	{
		{
			VEngine::TimeScheduler scheduler(nullptr);

			struct SchedulerTest
			{
				int _counter{0};

				void update( float deltaTime )
				{
					_counter++;
				};
			} testObj;

			scheduler.addUpdateFunc( std::bind(&SchedulerTest::update, &testObj, std::placeholders::_1), &testObj );

			int ticksAmount = 100;

			for( int i = 0; i < ticksAmount; i++ )
			{
				scheduler.doMainTick();
			}

			BOOST_TEST( testObj._counter == ticksAmount, "wrong ticks propagation" );
		}
	}
}

BOOST_AUTO_TEST_SUITE( TimeSchedulerTestSuite )

BOOST_AUTO_TEST_CASE( membersInit )
{
	UnitTests::TimeSchedulerTest::membersInit();
}

BOOST_AUTO_TEST_CASE( addUpdateFuncMethodWork )
{
	UnitTests::TimeSchedulerTest::addUpdateFuncMethodWork();
}

BOOST_AUTO_TEST_CASE( delUpdateFuncMethodWork )
{
	UnitTests::TimeSchedulerTest::delUpdateFuncMethodWork();
}

BOOST_AUTO_TEST_CASE( doMainTickMethodWork )
{
	UnitTests::TimeSchedulerTest::doMainTickMethodWork();
}

BOOST_AUTO_TEST_SUITE_END()