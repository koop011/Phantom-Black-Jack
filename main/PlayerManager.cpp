//
//  PlayerManager.cpp
//  blackJack
//
//  Created by Leo on 8/9/2024.
//

#include <iostream>
#include <string>
#include "Player.hpp"


void Player::receiveCard(const Cards& card) {
    hand.push_back(card);
}

void Player::showHand() {
    for (auto& card : hand) {
        std::cout << card.toString() << std::endl;
    }
}

bool Player::checkTotal() {
    int totalHandValue = 0;
    for (auto& card : hand) {
        totalHandValue = totalHandValue + card.getValue();
    }
    
    if (totalHandValue > 21) {
        // player gameover
        return false;
    }
    
    // player continues
    return true;
}

