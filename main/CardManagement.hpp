#ifndef CardManagement_hpp
#define CardManagement_hpp

#define HouseOfCards 13
#define SuitOfCards 4

#include <stdio.h>
#include <vector>
#include "Cards.hpp"

class CardManagement
{
public:
    auto drawCard();
    void removeCardFromDeck(Cards card);
    void showDeck();
    std::vector<Cards> getDeck();
    void createDeck();
    void shuffle();
    Cards getCard();

private:
    std::vector<Cards> deck;
    std::vector<Cards> removedCards;
};

#endif /* createDeckOfCards_hpp */
