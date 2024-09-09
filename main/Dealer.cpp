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
}

void Dealer::playTurn(CardManagement *CM)
{
    bool stay = false;
    bool lose = Dealer::getLose();

    while (!stay && !lose)
    {
        checkHand();
        if (checkTotal(Dealer::getName()) < Constants::dealerHitThreshHold)
        {
            std::cout << std::format("{} is hitting! \n", Dealer::getName());
            receiveCard(CM->getCard());
            showHand();
        }

        if (checkTotal(Dealer::getName()) > Constants::blackJack)
        {
            std::cout << "--------------Dealer Turn End----------------\n";
            dealerLose();
            lose = true;
        }
        else
        {
            std::cout << "--------------Dealer Turn End----------------\n";
            std::cout << std::format("{} is staying! \n", Dealer::getName());
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
    if ((checkTotal(name) + highAceOffSet) > Constants::dealerHitThreshHold)
    {
        return true;
    }
    return false;
}

void Dealer::setName()
{
    name = "Dealer";
}

void Dealer::dealerLose()
{
    std::cout << "**************\n";
    std::cout << std::format("{} LOST! \n\n", name);
    std::cout << "**************\n";
}

void Dealer::dealerWin()
{
    std::cout << "**************\n";
    std::cout << std::format("{} WON! \n\n", name);
    std::cout << "**************\n";
}

std::string Dealer::getName()
{
    return name;
}