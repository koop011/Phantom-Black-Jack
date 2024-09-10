#include "Dealer.hpp"
#include "Constants.h"
#include <iostream>

void Dealer::showHand(bool initial)
{
    for (auto &card : hand)
    {
        if (&card == &hand.back() && initial)
        {
            std::cout << card.showHidden() << "\n";
        }
        else
        {
            std::cout << card.toString() << " ";
        }
    }
    std::cout << "\n";
}

void Dealer::playTurn(CardManagement *CM, int playerPosition)
{
    bool stay = false;
    bool lose = getLose();

    while (!stay && !lose)
    {
        checkHand();
        if (checkTotal(getName()) < Constants::dealerHitThreshHold)
        {
            std::cout << getName() + " is hitting!" << std::endl;
            receiveCard(CM->getCard());
            showHand();
        }

        if (checkTotal(getName()) > Constants::blackJack)
        {
            std::cout << "--------------Dealer Turn End----------------" << std::endl;
            playerLose();
            lose = true;
        }
        else if (checkTotal(getName()) >= Constants::dealerHitThreshHold)
        {
            std::cout << "--------------Dealer Turn End----------------" << std::endl;
            std::cout << getName() + " is staying! \n";
            stay = true;
            showHand();
        }
    }
}

void Dealer::checkHand()
{
    for (int card = 0; card < hand.size(); ++card)
    {
        if (hand[card].ranks == Cards::Ranks::Ace)
        {
            std::cout << getName() << " got an Ace!" << std::endl;
            if (useHighAce(hand[card]))
            {
                hand[card].ranks = Cards::Ranks::HighAce;
            }
        }
    }
}

bool Dealer::useHighAce(Cards card)
{
    int highAceOffSet = 10;
    if ((checkTotal(getName()) + highAceOffSet) > Constants::dealerHitThreshHold)
    {
        std::cout << getName() << " is converting Ace to HighAce!" << std::endl;
        return true;
    }
    std::cout << getName() << " choosing to stick with LowAce!" << std::endl;
    return false;
}

void Dealer::playerLose()
{
    std::cout << "**************\n";
    std::cout << getName() + " LOST! \n";
    std::cout << "**************\n";
}