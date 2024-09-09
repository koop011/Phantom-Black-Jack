//
//  Dealer.hpp
//  blackJack
//
//  Created by Leo on 8/9/2024.
//

#ifndef Dealer_hpp
#define Dealer_hpp

#include <stdio.h>
#include "Player.hpp"

class Dealer : public Player
{
public:
    Dealer() : Player(false)
    {
        name = "Dealer";
    }
    std::string name;
    void setName();
    void showHand(bool initial = false);
    bool gameProgressCheck();
    void playTurn(CardManagement *CM);
    void checkHand();
    void dealerWin();
    std::string getName();
    void dealerLose();

private:
    bool useHighAce(Cards card);
};
#endif /* Dealer_hpp */
