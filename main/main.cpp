// Phantom Works Code Challenge 2024

#include <iostream>
#include <string>
#include "CardManagement.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Constants.h"
#include <regex>
#include <memory>

using std::string;

enum gameState : u_char
{
    menu,
    playing,
    result,
    end,
    endProgram
};

gameState addPlayers(gameState state, std::unique_ptr<std::vector<Player>> &players)
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
        std::cout << "[Insert number of players]" << std::endl;
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

    for (int playerPosition = 0; playerPosition < numberOfPlayers; ++playerPosition)
    {
        Player singlePlayer(playerPosition);
        players->push_back(singlePlayer);
    }

    std::cout << "Dealing cards for " + userInput + " players." << std::endl;

    return gameState::playing;
}

gameState gamePlay(gameState state, std::unique_ptr<std::vector<Player>> &players, std::unique_ptr<Dealer> &dealer)
{
    CardManagement CM;
    bool initialRound = true;
    int playerPosition = 0;
    int initialRoundOffSet = 2;
    CM.createDeck();
    CM.shuffle();

    while (state == gameState::playing)
    {
        while (initialRound)
        {
            // initial hands deal
            // gives out 2 rounds of cards to players
            for (int initialDeal = 0; initialDeal < initialRoundOffSet; ++initialDeal)
            {
                for (int i = 0; i < players->size(); i++)
                {
                    players->at(i).receiveCard(CM.getCard());
                }
                dealer->receiveCard(CM.getCard());
            }

            std::cout << "Dealers Hand: " << std::endl;
            dealer->showHand(initialRound);
            initialRound = false;
        }

        std::cout << players->size() << " number players" << std::endl;
        // players turn
        for (int i = 0; i < players->size(); ++i)
        {
            players->at(i).playTurn(&CM, playerPosition);
            playerPosition++;
        }
        playerPosition = 0;

        // dealers turn
        std::cout << "------------------------------------------\n";
        std::cout << dealer->getName() + "'s turn. " << std::endl;
        dealer->playTurn(&CM);

        state = gameState::result;
    }
    return state;
}

gameState gameResult(gameState state, std::vector<Player> *players, std::unique_ptr<Dealer> &dealer)
{
    std::cout << "\n------------------------------------------\n";
    std::cout << "------------- Game Result -------------\n";
    std::cout << "------------------------------------------" << std::endl;
    bool resultState = true;
    std::vector<Player> lostPlayers;
    std::vector<Player> tiedPlayers;
    std::vector<Player> wonPlayers;
    dealer->setResult(resultState);

    for (Player player : *players)
    {
        player.setResult(resultState);

        if (player.getLose())
        {
            lostPlayers.push_back(player);
        }
        else if ((player.getResult() < dealer->getResult()) && !dealer->getLose())
        {
            lostPlayers.push_back(player);
        }
        else if (dealer->getLose())
        {
            wonPlayers.push_back(player);
        }
        else if ((player.getResult() > dealer->getResult()) && !dealer->getLose())
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
    std::cout << "------------------------------------------" << std::endl;

    return gameState::end;
}

gameState gameEnd(gameState state)
{
    // replay
    bool playAgain = false;
    string playAgainInput;
    while (!playAgain && state == gameState::end)
    {
        std::cout << "\nWould you like to play again? [y/n]" << std::endl;
        std::cin >> playAgainInput;
        if (!playAgainInput.compare("y"))
        {
            state = gameState::menu;
            playAgain = true;
        }
        else if (!playAgainInput.compare("n"))
        {
            std::cout << "Thanks for playing Phantom Jack!" << std::endl;
            state = gameState::endProgram;
        }
        else
        {
            std::cout << Constants::invalidResponse;
        }
    }
    return state;
}

int main(int argc, const char *argv[])
{
    // TODO Logging
    // TODO unit testing
    gameState state;
    std::unique_ptr<std::vector<Player>> players = std::make_unique<std::vector<Player>>();
    std::unique_ptr<Dealer> dealer = std::make_unique<Dealer>();

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
    std::cout << "   e.g. Dealer has: 6S [] \n"
              << std::endl;

    state = gameState::menu;

    while (state != gameState::endProgram)
    {
        switch (state)
        {
        case gameState::menu:
            state = addPlayers(state, players);
            break;
        case gameState::playing:
            state = gamePlay(state, players, dealer);
            break;
        case gameState::result:
            state = gameResult(state, players.get(), dealer);
        case gameState::end:
            state = gameEnd(state);
            players->clear();
            dealer.reset(new Dealer());
            break;
        default:
            break;
        }
    }

    return 0;
}
