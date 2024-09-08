//
//  createDeckOfCards.cpp
//  blackJack
//
//  Created by Leo on 6/9/2024.
//

#include "CardManagement.hpp"
#include <iostream>
#include <vector>
#include <random>

void CardManagement::createDeck() {
    deck.clear();
    
    for (int suit = 0; suit < 4; ++suit) {  // 4 suits
        for (int rank = 0; rank < 13; ++rank) {  // 13 ranks
//            deck.push_back(Cards{static_cast<Cards::Ranks>(rank), static_cast<Cards::Suits>(suit)});
            // TODO: fix for loop
            deck.push_back(Cards{static_cast<Cards::Ranks>(rank), static_cast<Cards::Suits>(suit)});
        }
    }
}

void CardManagement::removeCardFromDeck(Cards card) {
    deck.erase(deck.begin());
    removedCards.push_back(card);
}

void CardManagement::shuffle() {
    std::random_device rd;
      //std::default_random_engine gen(rd);

    std::shuffle (deck.begin(), deck.end(), rd);
}

void CardManagement::showDeck() {
    std::cout << deck.size() << "\n";
    for (int cards = 0; cards < deck.size(); ++cards) {
        std::cout << deck[cards].toString() << '\n';
    }
}

Cards CardManagement::getCard(){
    Cards front = deck.front();
    removeCardFromDeck(front);
    return front;
}

std::vector<Cards> CardManagement::getDeck(){
    return deck;
}
