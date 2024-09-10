#ifndef Dealer_hpp
#define Dealer_hpp

#include <stdio.h>
#include "Player.hpp"

class Dealer : public Player
{
public:
    Dealer() : Player(0, "Dealer") {}
    void showHand(bool initial = false);
    void playTurn(CardManagement *CM, int playerPosition = 0) override;
    void checkHand() override;
    void playerLose() override;

private:
    bool useHighAce(Cards card);
};
#endif /* Dealer_hpp */
