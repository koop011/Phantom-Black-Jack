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

class Player
{
public:
    Player(int playerPosition)
    {
        name = std::format("Player {}", playerPosition);
    }
    std::string name;
    std::vector<Cards> hand;
    virtual std::string getName();

    void receiveCard(Cards card);
    void showHand();
    int checkTotal(std::string name, bool result = false);
    void playerLose();
    void tie();
    void checkHand();
    virtual void playTurn(CardManagement *CM, int playerPosition);
    void setName(int playerPosition);
    void playerWin();
    void playerDraw();
    bool getLose();
    void setLose();
    void setResult(bool result);
    int getResult();

private:
    void setDraw();
    bool draw = false;
    bool lose = false;
    int finalScore = 0;
};

#endif /* PlayerManager_hpp */
