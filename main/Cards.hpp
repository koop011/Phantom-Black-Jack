//
//  Cards.hpp
//  blackJack
//
//  Created by Leo on 7/9/2024.
//

#ifndef Cards_h
#define Cards_h

struct Cards {
    enum class Suits {
        clubs,
        diamonds,
        hearts,
        spades
    };
    
    enum class Ranks {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };
    
    Ranks ranks;
    Suits suits;
    
    
    std::string toString() const {
        static const std::string rankNames[] = {
            "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "Jack", "Queen", "King"
        };
        static const std::string suitNames[] = {
            "C", "D", "H", "S"
        };
        return rankNames[static_cast<int>(ranks)] + suitNames[static_cast<int>(suits)];
    }

    int getValue(bool useHighAce = false) const {
        if (ranks == Ranks::Ace) {
            return useHighAce ? 11 : 1;
        } else if (ranks >= Ranks::Two && ranks <= Ranks::Ten) {
            return static_cast<int>(ranks) + 1; // Since Two is 1, add 2 to get the correct value
        } else {
            return 10;  // Jack, Queen, King all count as 10
        }
    }
    
};

#endif /* Cards_h */
