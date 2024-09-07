//
//  createDeckOfCards.cpp
//  blackJack
//
//  Created by Leo on 6/9/2024.
//

#include "CardManagement.hpp"
#include <iostream>
#include <vector>




void CardManagement::createDeck() {
    deck.clear();
    
    for (int suit = 0; suit < 4; ++suit) {  // 4 suits
        for (int rank = 0; rank < 13; ++rank) {  // 13 ranks
            deck.push_back(Cards{static_cast<Cards::Ranks>(rank), static_cast<Cards::Suits>(suit)});
        }
    }
}



//int* CardManagement::get_deck_of_cards(){
//    int deck[DeckOfCards];
//    int sizeOfDeck = sizeof(deck)/sizeof(deck[0]);
//    for (int i = 0; i < sizeOfDeck; ++i) {
//        deck[i] = i;
//        cout << deck[i] << endl;
//    }
//    return deck;
//}



//std::vector<int> CardManagement::get_deck_of_cards() {
//    static std::vector<int> arr(DeckOfCards);
//    for (int i = 0; i < DeckOfCards; ++i) {
//        arr[i] = i * 2;  // Example initialization
//    }
//    return arr;
//}
//
//std::vector<int> CardManagement::get_house_of_cards() {
//    std::vector<int> arr(HouseOfCards);
//    
//}

