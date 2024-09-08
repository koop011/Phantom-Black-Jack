#define BOOST_TEST_MODULE my_unit_tests
#include <boost/test/unit_test.hpp> // Boost test library
int addNumbers(int a, int b)
{
    return a + b;
}
BOOST_AUTO_TEST_SUITE(Demo)     // Test suite declaration
BOOST_AUTO_TEST_CASE(Demo_test) // Sample test case
{
    BOOST_CHECK_EQUAL(5, addNumbers(2, 3));
}
BOOST_AUTO_TEST_SUITE_END()
