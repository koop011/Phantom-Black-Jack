//
//  PlayerManager.hpp
//  blackJack
//
//  Created by Leo on 8/9/2024.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Cards.hpp"
#include <vector>
#include "CardManagement.hpp"
#include <format>

class Player {
public:
    Player (int playerPosition) {
        name = std::format("Player {}", playerPosition);
    }
    std::string name;
    std::vector<Cards> hand;    
    virtual std::string getName();
    bool lose = false;
    void receiveCard(Cards card);
    void showHand();
    int checkTotal();
    void checkWin();
    void tie();
    void checkHand();
    virtual void playTurn(CardManagement *CM, int playerPosition);
    void setName(int playerPosition);
    void playerWin();
    void playerDraw();
    
};

#endif /* PlayerManager_hpp */
