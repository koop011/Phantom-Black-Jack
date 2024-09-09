// Phantom Works Code Challenge 2024

#include <iostream>
#include <format>
#include <string>
#include "CardManagement.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Constants.h"
#include <regex>

using std::string;

enum gameState : u_char
{
    menu,
    playing,
    end,
    endProgram
};

int addPlayers(gameState *state)
{
    string userInput;
    bool inputGiven = false;
    int numberOfPlayers = 0;
    std::regex integer("(\\+|-)?[[:digit:]]+");
    // check if int is supplied
    while (!inputGiven)
    {
        inputGiven = false;
        std::cout << "How many players? \n";
        std::cout << "[Insert number of players] \n";
        std::cin >> userInput;

        try
        {
            // TODO: match with regex so no input with number + string can be matched
            numberOfPlayers = stoi(userInput);
            inputGiven = true;
        }
        catch (std::invalid_argument)
        {
            std::cout << Constants::invalidResponse;
        }
    }

    std::cout << std::format("Dealing cards for {} players. \n", userInput);

    *state = gameState::playing;
    return numberOfPlayers;
}

void gamePlay(gameState *state, int numberOfPlayers)
{
    CardManagement CM;

    std::vector<Player> players;
    int dealerPosition = numberOfPlayers; // size of players will give the final position in vector
    bool initialRound = true;
    Dealer dealer;
    int initialRoundOffSet = 2;
    CM.createDeck();
    CM.shuffle();

    for (int playerPosition = 0; playerPosition < numberOfPlayers; ++playerPosition)
    {
        Player singlePlayer(playerPosition);
        players.push_back(singlePlayer);
    }

    while (*state == gameState::playing)
    {
        while (initialRound)
        {
            // initial hands deal
            for (int initialDeal = 0; initialDeal < initialRoundOffSet; ++initialDeal)
            { // gives out 2 rounds of cards to players
                for (auto &player : players)
                {
                    // if (&player != &players.back()) {
                    player.receiveCard(CM.getCard());
                    //                    } else {
                    //
                    //                    }
                }
                dealer.receiveCard(CM.getCard());
            }

            // dealer shows hand
            std::cout << "Dealers Hand: \n";
            dealer.showHand(initialRound);
            std::cout << "\n";
            initialRound = false;
        }

        // reveal the players card on their turn
        // if receiving ace ask player to choose

        for (int playerPosition = 0; playerPosition < players.size(); ++playerPosition)
        {

            std::cout << "------------------------------------------\n";
            std::cout << std::format("{}'s turn. \n", players[playerPosition].getName());

            players[playerPosition].showHand();
            players[playerPosition].checkHand();
            players[playerPosition].playTurn(&CM, playerPosition);
        }

        std::cout << "------------------------------------------\n";
        std::cout << std::format("{}'s turn. \n", dealer.getName());
        dealer.playTurn(&CM);

        std::cout << "\n------------------------------------------\n";
        std::cout << "------------- Game Result -------------\n";
        std::cout << "------------------------------------------\n";
        bool resultState = true;
        std::vector<Player> lostPlayers;
        std::vector<Player> tiedPlayers;
        std::vector<Player> wonPlayers;
        dealer.setResult(resultState);

        for (Player &player : players)
        {
            player.setResult(resultState);

            if (player.getLose())
            {
                lostPlayers.push_back(player);
            }
            else if ((player.getResult() < dealer.getResult()) && !dealer.getLose())
            {
                lostPlayers.push_back(player);
            }
            else if (dealer.getLose())
            {
                wonPlayers.push_back(player);
            }
            else if ((player.getResult() > dealer.getResult()) && !dealer.getLose())
            {
                wonPlayers.push_back(player);
            }
            else
            {
                tiedPlayers.push_back(player);
            }
        }

        for (Player player : lostPlayers)
        {
            player.playerLose();
        }
        for (Player player : tiedPlayers)
        {
            player.playerDraw();
        }
        for (Player player : wonPlayers)
        {
            player.playerWin();
        }

        std::cout << "\n------------------------------------------\n";
        std::cout << "------------- Game END -------------\n";
        std::cout << "------------------------------------------\n";

        *state = gameState::end;
    }
}

void gameEnd(gameState *state)
{
    // replay
    bool playAgain = false;
    string playAgainInput;
    while (!playAgain && *state == gameState::end)
    {
        std::cout << "\nWould you like to play again? [y/n]\n";
        std::cin >> playAgainInput;
        if (!playAgainInput.compare("y"))
        {
            *state = gameState::menu;
            playAgain = true;
        }
        else if (!playAgainInput.compare("n"))
        {
            std::cout << "Thanks for playing Phantom Jack! \n";
            *state = gameState::endProgram;
        }
        else
        {
            std::cout << Constants::invalidResponse;
        }
    }
}

int main(int argc, const char *argv[])
{

    gameState state;
    int numberOfPlayers;
    std::cout << "<<------------------------------------------------------>> \n";
    std::cout << "               Welcome to Phantom Black Jack \n";
    std::cout << "<<------------------------------------------------------>> \n\n";
    std::cout << "Card instructions: \n";
    std::cout << "   In Phantom Black Jack, card rank such as Jack, Queen, King are all valued at 10. \n";
    std::cout << "   Cards will be represented with rank followed by the first letter of the suit. \n";
    std::cout << "       e.g. 5 of Heart will be represented as 5H. \n";
    std::cout << "       e.g. King of Heart will be represented as KH. \n";
    std::cout << "   Additionally, if any cards are hidden, it'll be represented with []. \n\n";
    std::cout << "As an example, the dealer will show 6 of spades and a hidden card as: \n";
    std::cout << "   e.g. Dealer has: 6S [] \n\n";

    state = gameState::menu;
    // state = gameState::playing;

    while (state != gameState::endProgram)
    {
        switch (state)
        {
        case gameState::menu:
            numberOfPlayers = addPlayers(&state);
            break;
        case gameState::playing:
            gamePlay(&state, numberOfPlayers);
            break;
        case gameState::end:
            gameEnd(&state);
            break;
        default:
            break;
        }
    }

    return 0;
}
