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
