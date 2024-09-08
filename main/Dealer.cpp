//
//  Dealer.cpp
//  blackJack
//
//  Created by Leo on 8/9/2024.
//

#include "Dealer.hpp"
#include <iostream>

void Dealer::showHand(bool initial) {
    for (auto& card : hand) {
        if (&card == &hand.back() && initial){
            std::cout << card.showHidden() << "\n";
        } else {
            std::cout << card.toString() << " ";
        }
    }
}

//bool Dealer::gameProgressCheck() {
//    if (winOrLose){
//        return true;
//    }
//    return false;
//}

void Dealer::dealerWins() {
    std::cout << "Dealer wins! \n Game Over! \n";
}

void Dealer::playTurn(CardManagement *CM){
    bool stay = false;
    
    while (!stay){
        checkHand();
        if (checkTotal() < 17) {
            receiveCard(CM->getCard());
            showHand();
            checkTotal();            
        } else {
            stay = true;
            showHand();
        }
    }
}

void Dealer::checkHand() {
    for (int card = 0; card < hand.size(); ++card) {
        if (hand[card].ranks == Cards::Ranks::Ace){
            if (useHighAce(hand[card])){
                hand[card].ranks == Cards::Ranks::HighAce;
            }
        }
    }
}

bool Dealer::useHighAce(Cards card){
    int stayThreshHold = 17;
    int highAceOffSet = 10;
    if ((checkTotal() + highAceOffSet) > stayThreshHold){
        return true;
    }
    return false;
}

void Dealer::setName() {
    name = "Dealer";
}

void Dealer::dealerWin() {
    std::cout << "**************\n";
    std::cout << std::format("{} WON! \n\n", name);
    std::cout << "**************\n";
}
