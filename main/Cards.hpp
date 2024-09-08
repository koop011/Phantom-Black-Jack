//
//  Cards.hpp
//  blackJack
//
//  Created by Leo on 7/9/2024.
//

#ifndef Cards_h
#define Cards_h
#include <string> // why? i didn't need it before

struct Cards {
    enum class Suits {
        clubs,
        diamonds,
        hearts,
        spades
    };
    
//    enum class Ranks {
//        Ace     = 1,
//        Two     = 2,
//        Three   = 3,
//        Four    = 4,
//        Five    = 5,
//        Six     = 6,
//        Seven   = 7,
//        Eight   = 8,
//        Nine    = 9,
//        Ten     = 10,
//        Jack    = 10,
//        Queen   = 10,
//        King    = 10,
//        HighAce = 11,
//    };
    
    enum class Ranks {
        Ace     ,
        Two     ,
        Three   ,
        Four    ,
        Five    ,
        Six     ,
        Seven   ,
        Eight   ,
        Nine    ,
        Ten     ,
        Jack    ,
        Queen   ,
        King    ,
        HighAce ,
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

    int getValue() const {
        if (ranks <= Ranks::Nine) {
            return static_cast<int>(ranks) + 1;
        } else if (ranks == Ranks::HighAce) {
            return 11;
        } else {
            return 10;  // Jack, Queen, King all count as 10
        }
        //return (int)ranks;
    }
    
    std::string showHidden() const {
        return "[]";
    }
};

#endif /* Cards_h */
