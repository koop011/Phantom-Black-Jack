//
//  PlayerManager.cpp
//  blackJack
//
//  Created by Leo on 8/9/2024.
//

#include <iostream>
#include <string>
#include "Player.hpp"
#include <format>
#include "Constants.h"

using std::string;

void Player::receiveCard(Cards card) {
    hand.push_back(card);
}

void Player::showHand() {
    for (auto& card : hand) {
        std::cout << card.toString() << " ";
    }
    
    std::cout << "\n";
    checkTotal();
}

void Player::playerWin() {
    std::cout << "**************\n";
    std::cout << std::format("{} WON! \n\n", name);
    std::cout << "**************\n";
}

void Player::playerDraw() {
    std::cout << "---------------\n";
    std::cout << std::format("{} Draw! Good luck next time!\n", name);
    std::cout << "---------------\n";
}

int Player::checkTotal() {
    int totalHandValue = 0;
    for (auto card : hand) {
        totalHandValue += card.getValue();
    }
    
    std::cout << std::format("Current hand total: {} \n", totalHandValue);
    
    if (totalHandValue > 21) {
        lose = true;
    } else if (totalHandValue == 21){
        lose = false;
    }
    checkWin();
    
    return totalHandValue;
}

void Player::checkHand() {
    std::optional<string> useHighAce;
    string userInput;
    bool inputValid = false;
    
    
    for (int card = 0; card < hand.size(); ++card) {
        inputValid = false;
        if (hand[card].ranks == Cards::Ranks::Ace){
            while (!inputValid){
                std::cout << "You've got an Ace! Convert to 11? [y/n] \n";
                std::cin >> userInput;
                
                if (!userInput.compare("y") && !userInput.compare("n")){
                    std::cout << Constants::invalidResponse;
                } else if (!userInput.compare("y")){
                    hand[card].ranks = Cards::Ranks::HighAce;
                    inputValid = true;
                    checkTotal();
                } else {
                    inputValid = true;
                }
            }
        }
    }
}

// TODO : fix logic
void Player::checkWin(){
//    if (!lose) {
//        std::cout << "You've got Phantom Black Jack! \n Congratualations! \n";
//        return true;
//    } else {
    if (lose){
        std::cout << "---------------------\n";
        std::cout << "You busted! \nTry again next time! \n";
        std::cout << "---------------------\n";
    }
}

void Player::tie(){
    std::cout << "you've tied! \n";
}

void Player::playTurn(CardManagement *CM, int playerPosition){
    std::optional<string> hitOrStay;
    string userInput;
    bool stay = false;
    
    while (!stay){
        std::cout << "\n";
        std::cout << "Would you like to Hit or Stay? [h/s] \n";
        std::cin >> userInput;
        hitOrStay = userInput;

        if (!hitOrStay.value().compare("h")){
            receiveCard(CM->getCard());
            checkTotal();
            
            if (lose) {
                stay = true;
            }

        } else if (!hitOrStay.value().compare("s")){
            std::cout << std::format("Player {} is staying with current hand! \n\n", playerPosition);
            stay = true;
        } else {
            std::cout << Constants::invalidResponse;
        }
    }
}

std::string Player::getName() {
    return name;
}


