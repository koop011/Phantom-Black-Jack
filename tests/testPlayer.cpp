#include <boost/test/unit_test.hpp> // Boost test library
int addNumber(int a, int b)
{
    return a + b;
}
BOOST_AUTO_TEST_SUITE(Tests)           // Test suite declaration
BOOST_AUTO_TEST_CASE(TestCardAddition) // Sample test case
{
    BOOST_CHECK_EQUAL(5, addNumber(2, 3));
}

BOOST_AUTO_TEST_CASE(TestPlayerDeck) // Sample test case
{
    BOOST_CHECK_EQUAL(5, addNumber(2, 3));
}
BOOST_AUTO_TEST_SUITE_END()
