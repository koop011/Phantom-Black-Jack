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

class Dealer : public Player {
public:
    Dealer() : Player(false) {
        name = "Dealer";
    }
    void setName();
    void showHand(bool initial = false); // override?
    bool gameProgressCheck();
    void dealerWins();
    void playTurn(CardManagement *CM);
    void checkHand();
    void dealerWin();
    //void playTurn(CardManagement *CM, int playerPosition) override;
private:
    bool useHighAce(Cards card);
    //std::vector<Cards> hand;
};
#endif /* Dealer_hpp */
