#define BOOST_TEST_MODULE my master test suite name
#include "../include/boost/test/unit_test.hpp"
//#include <include/boost/test/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE( free_test_function )
{
  BOOST_TEST( true /* test assertion */ );
}

BOOST_AUTO_TEST_SUITE( test_suite1 )

BOOST_AUTO_TEST_CASE( test_case1 )
{
    BOOST_WARN( sizeof(int) < 4 );
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
    BOOST_REQUIRE_EQUAL( 1, 2 );
    BOOST_FAIL( "Should never reach this line" );
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE( test_suite2 )

BOOST_AUTO_TEST_CASE( test_case3 )
{
    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_CASE( test_case4 )
{
    BOOST_CHECK( false );
}

BOOST_AUTO_TEST_SUITE_END()
