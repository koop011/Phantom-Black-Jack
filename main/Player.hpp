#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Cards.hpp"
#include <vector>
#include "CardManagement.hpp"

class Player
{
public:
    Player(int playerPosition, std::string overrideName = "")
    {
        if (!overrideName.empty())
        {
            name = overrideName;
        }
        else
        {
            name = "Player " + std::to_string(playerPosition);
        }
    }

    std::vector<Cards> hand;
    std::string getName();

    void receiveCard(Cards card);
    void showHand();
    int checkTotal(std::string name, bool result = false);
    virtual void playerLose();
    virtual void checkHand();
    virtual void playTurn(CardManagement *CM, int playerPosition);
    void playerWin();
    void playerDraw();
    bool getLose();
    void setLose();
    void setResult(bool result);
    int getResult();

private:
    bool lose = false;
    int finalScore = 0;
    std::string name;
};

#endif /* PlayerManager_hpp */
