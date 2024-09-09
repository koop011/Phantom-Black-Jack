#define BOOST_TEST_MODULE my_unit_tests
#include <boost/test/unit_test.hpp> // Boost test library
#include "../main/Cards.hpp"
#include "../main/CardManagement.hpp"
#include <iostream>
#include <vector>
#include <random>

// CardManagement CM;
// Cards card = {
//     Cards::Ranks::Ace,
//     Cards::Suits::clubs,
// };

// std::vector<Cards> originalDeck()
// {
//     std::vector<Cards> deck;
//     CM.createDeck();

//     return deck = CM.getDeck();
// }

// std::vector<Cards> newDeck()
// {
//     std::vector<Cards> deck;
//     CM.createDeck();

//     return deck = CM.getDeck();
// }

// int removeCardFromDeck()
// {
//     CM.createDeck();
//     std::vector<Cards> deck = CM.getDeck();
//     int sizeOfDeck = 0;

//     CM.removeCardFromDeck(card);
//     return sizeOfDeck = deck.size();
// }

// int addNumbers(int a, int b)
// {
//     return a + b;
// }
BOOST_AUTO_TEST_SUITE(CardsTest) // Test suite declaration
BOOST_AUTO_TEST_CASE(TestDeck)   // Sample test case
{
    // BOOST_CHECK_EQUAL(5, addNumbers(2, 3));
    // BOOST_CHECK_EQUAL_COLLECTIONS(originalDeck().begin(), originalDeck().end(),
    //                               newDeck().begin(), newDeck().end());
    // BOOST_CHECK_EQUAL(removeCardFromDeck(), 51);
}
BOOST_AUTO_TEST_SUITE_END()
