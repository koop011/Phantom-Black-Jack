#include <iostream>
#include <string>
#include "Player.hpp"
#include "Constants.h"
#include <optional>

using std::string;

void Player::receiveCard(Cards card)
{
    hand.push_back(card);
}

void Player::showHand()
{
    for (auto &card : hand)
    {
        std::cout << card.toString() << " ";
    }

    std::cout << "\n";
    checkTotal(name);
}

void Player::playerWin()
{
    std::cout << "**************\n";
    std::cout << name + " WON! \n\n";
    std::cout << "**************\n";
}

void Player::playerDraw()
{
    std::cout << "---------------\n";
    std::cout << name + " Draw with Dealer! Good luck next time!\n";
    std::cout << "---------------\n";
}

void Player::playerLose()
{
    std::cout << "---------------------\n";
    std::cout << name + ", You Lost! \nTry again next time! \n";
    std::cout << "---------------------" << std::endl;
}

int Player::checkTotal(string name, bool result)
{
    int totalHandValue = 0;
    for (auto card : hand)
    {
        totalHandValue += card.getValue();
    }
    if (!result)
    {
        std::cout << name << "'s hand total: " << totalHandValue << " " << std::endl;
    }

    if (totalHandValue > Constants::blackJack)
    {
        setLose();
    }

    return totalHandValue;
}

void Player::checkHand()
{
    std::optional<string> useHighAce;
    string userInput;
    bool inputValid = false;

    for (int card = 0; card < hand.size(); ++card)
    {
        inputValid = false;
        if (hand[card].ranks == Cards::Ranks::Ace)
        {
            while (!inputValid)
            {
                std::cout << "You've got an Ace! Convert to 11? [y/n] \n";
                std::cin >> userInput;

                if (!userInput.compare("y"))
                {
                    hand[card].ranks = Cards::Ranks::HighAce;
                    inputValid = true;
                    checkTotal(name);
                }
                else if (!userInput.compare("n"))
                {
                    hand[card].ranks = Cards::Ranks::LowAce;
                    inputValid = true;
                }
                else
                {
                    std::cout << Constants::invalidResponse;
                }
            }
        }
    }
}

void Player::playTurn(CardManagement *CM, int playerPosition)
{
    std::optional<string> hitOrStay;
    string userInput;
    bool stay = false;

    std::cout << "------------------------------------------\n";
    std::cout << getName() << "'s turn. " << std::endl;

    showHand();
    checkHand();

    while (!stay)
    {
        std::cout << "\nWould you like to Hit or Stay? [h/s] \n";
        std::cin >> userInput;
        hitOrStay = userInput;

        if (!hitOrStay.value().compare("h"))
        {
            receiveCard(CM->getCard());
            showHand();
            checkHand();

            if (getLose())
            {
                stay = true;
            }
        }
        else if (!hitOrStay.value().compare("s"))
        {
            std::cout << "Player " << playerPosition << " is staying with current hand! \n"
                      << std::endl;
            stay = true;
        }
        else
        {
            std::cout << Constants::invalidResponse << std::endl;
        }
    }
}

std::string Player::getName()
{
    return name;
}

bool Player::getLose()
{
    return lose;
}

void Player::setLose()
{
    lose = true;
}

void Player::setResult(bool resultState)
{
    finalScore = checkTotal(name, resultState);
}

int Player::getResult()
{
    return finalScore;
}