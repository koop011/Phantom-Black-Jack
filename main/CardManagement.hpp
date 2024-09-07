//
//  createDeckOfCards.hpp
//  blackJack
//
//  Created by Leo on 6/9/2024.
//

#ifndef CardManagement_hpp
#define CardManagement_hpp

#define DeckOfCards 52
#define HouseOfCards 13

#include <stdio.h>
#include <vector>
#include "Cards.hpp"

class CardManagement {
public:
    void createDeck();
    auto shuffle();
    auto drawCard();
    auto discardCard();
private:
    std::vector<Cards> deck;
};

#endif /* createDeckOfCards_hpp */
