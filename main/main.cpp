// Phantom Works Code Challenge 2024

#include <iostream>
#include <format>
#include "CardManagement.hpp"
using namespace std;

enum gameState : u_char {
    menu,
    playing,
    end
};

void numberOfPlayers(gameState& state, u_int& playerCount) {
    cout << "How many players? \n";
    cout << "[Insert number of players] \n";
    cin >> playerCount;
    cout << format("Dealing cards for {} players. \n", playerCount);
    
    state = gameState::playing;
}

void gamePlay() {
    CardManagement CM;
    // shuffle/create the deck
    CM.createDeck();
    
    // depending on the player go around and give out 1 card each including the dealer (x2)
    
    // reveal the first card to players but have the 2nd card hidden
    
    // reveal the players card on their turn
    
    // receive player input to either hit or stay
    
    // if HIT calculate the result and if greater than 21, eliminate the player
    
    // if STAY move on to next player
    
    // when all player has given their choice, reveal 2nd card of dealer
    // if at this point dealer has 21, the house wins
    // if at this point a player has 21, it's a tie
    // if at this point dealer doesn't have 21 but a player does, that player wins
    
    // continue going around receiving players choices (hit/stay)
    
    // continue until either house wins or loses
}

int main(int argc, const char * argv[]) {
    
    gameState state;
    u_int players;
    cout << "<<------------------------------------------------------>> \n";
    cout << "               Welcome to Phantom Black Jack \n";
    cout << "<<------------------------------------------------------>> \n\n";
    cout << "Card instructions: \n";
    cout << "   In Phantom Black Jack, card rank such as Jack, Queen, King are all valued at 10. \n";
    cout << "   Cards will be represented with rank followed by the first letter of the suit. \n";
    cout << "       e.g. 5 of Heart will be represented as 5H. \n";
    cout << "       e.g. King of Heart will be represented as KH. \n";
    cout << "   Additionally, if any cards are hidden, it'll be represented with []. \n\n";
    cout << "As an example, the dealer will show 6 of spades and a hidden card as: \n";
    cout << "   e.g. Dealer has: 6S [] \n\n";
    
    state = gameState::menu;
    
    switch (state) {
        case gameState::menu:
            numberOfPlayers(state, players);
            break;
        case gameState::playing:
            
            break;
        case gameState::end:
            break;
        default:
            break;
    }
    
    return 0;
}
