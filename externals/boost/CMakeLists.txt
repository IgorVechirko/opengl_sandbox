CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )

project(boost.test VERSION 1.0 LANGUAGES CXX )

set( BOOST_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
set( BOOST_TEST_DIR ${BOOST_DIR}/libs/test )

set( BOOST_TEST_DEPENDENTH_INCLUDE_DIRS 
    ${BOOST_DIR}/libs/algorithm/include
    ${BOOST_DIR}/libs/assert/include
    ${BOOST_DIR}/libs/bind/include
    ${BOOST_DIR}/libs/config/include
    ${BOOST_DIR}/libs/container_hash/include
    ${BOOST_DIR}/libs/converion/include
    ${BOOST_DIR}/libs/core/include
    ${BOOST_DIR}/libs/detail/include
    ${BOOST_DIR}/libs/exception/include
    ${BOOST_DIR}/libs/function/include
    ${BOOST_DIR}/libs/integer/include
    ${BOOST_DIR}/libs/io/include
    ${BOOST_DIR}/libs/iterator/include
    ${BOOST_DIR}/libs/move/include
    ${BOOST_DIR}/libs/mpl/include
    ${BOOST_DIR}/libs/nowide/include
    ${BOOST_DIR}/libs/numeric/conversion/include
    ${BOOST_DIR}/libs/preprocessor/include
    ${BOOST_DIR}/libs/range/include
    ${BOOST_DIR}/libs/smart_ptr/include
    ${BOOST_DIR}/libs/static_assert/include
    ${BOOST_DIR}/libs/throw_exception/include
    ${BOOST_DIR}/libs/type_index/include
    ${BOOST_DIR}/libs/type_traits/include
    ${BOOST_DIR}/libs/utility/include
)


set( BOOST_TEST_INCLUDE_DIR ${BOOST_TEST_DIR}/include )
set( BOOST_TEST_INLUDES 
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/auto_unit_test.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/debug.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/debug_config.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/execution_monitor.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/floating_point_comparison.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/framework.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/minimal.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/output_test_stream.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/parameterized_test.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/predicate_result.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/prg_exec_monitor.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/progress_monitor.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/results_collector.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/results_reporter.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/test_case_template.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/test_exec_monitor.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/test_framework_init_observer.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/test_tools.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test_log.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test_log_formatter.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test_monitor.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test_parameters.hpp
    ${BOOST_TEST_INCLUDE_DIR}/boost/test/unit_test_suite.hpp
)

set( BOOST_TEST_SRC
    ${BOOST_TEST_DIR}/src/compiler_log_formatter.cpp
    ${BOOST_TEST_DIR}/src/cpp_main.cpp
    ${BOOST_TEST_DIR}/src/debug.cpp
    ${BOOST_TEST_DIR}/src/decorator.cpp
    ${BOOST_TEST_DIR}/src/execution_monitor.cpp
    ${BOOST_TEST_DIR}/src/framework.cpp
    ${BOOST_TEST_DIR}/src/junit_log_formatter.cpp
    ${BOOST_TEST_DIR}/src/plain_report_formatter.cpp
    ${BOOST_TEST_DIR}/src/progress_monitor.cpp
    ${BOOST_TEST_DIR}/src/results_collector.cpp
    ${BOOST_TEST_DIR}/src/results_reporter.cpp
    ${BOOST_TEST_DIR}/src/test_framework_init_observer.cpp
    ${BOOST_TEST_DIR}/src/test_main.cpp
    ${BOOST_TEST_DIR}/src/test_tools.cpp
    ${BOOST_TEST_DIR}/src/test_tree.cpp
    ${BOOST_TEST_DIR}/src/unit_test_log.cpp
    ${BOOST_TEST_DIR}/src/unit_test_main.cpp
    ${BOOST_TEST_DIR}/src/unit_test_monitor.cpp
    ${BOOST_TEST_DIR}/src/unit_test_parameters.cpp
    ${BOOST_TEST_DIR}/src/xml_log_formatter.cpp
    ${BOOST_TEST_DIR}/src/xml_report_formatter.cpp
)


add_library( boost.test INTERFACE )

target_include_directories( boost.test INTERFACE ${BOOST_TEST_INCLUDE_DIR} )
target_include_directories( boost.test INTERFACE ${BOOST_TEST_DEPENDENTH_INCLUDE_DIRS} )