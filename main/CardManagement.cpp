#include "CardManagement.hpp"
#include <iostream>
#include <vector>
#include <random>

void CardManagement::createDeck()
{
    deck.clear();

    for (int suit = 0; suit < SuitOfCards; ++suit) // 4 suits
    {
        for (int rank = 0; rank < HouseOfCards; ++rank) // 13 ranks
        {
            deck.push_back(Cards{static_cast<Cards::Ranks>(rank), static_cast<Cards::Suits>(suit)});
        }
    }
}

void CardManagement::removeCardFromDeck(Cards card)
{
    deck.erase(deck.begin());
    removedCards.push_back(card);
}

void CardManagement::shuffle()
{
    std::random_device rd;
    std::shuffle(deck.begin(), deck.end(), rd);
}

void CardManagement::showDeck()
{
    std::cout << deck.size() << "\n";
    for (int cards = 0; cards < deck.size(); ++cards)
    {
        std::cout << deck[cards].toString() << "\n";
    }
}

Cards CardManagement::getCard()
{
    Cards front = deck.front();
    removeCardFromDeck(front);
    return front;
}

std::vector<Cards> CardManagement::getDeck()
{
    return deck;
}
