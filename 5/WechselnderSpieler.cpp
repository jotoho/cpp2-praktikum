#ifndef INCLUDE_GUARD_WECHSELNDERSPIELER_CPP
#define INCLUDE_GUARD_WECHSELNDERSPIELER_CPP
#include "WechselnderSpieler.hpp"
#include <stdexcept>

HidingSpotType WechselnderSpieler::zweiterTipp(const HidingSpotType ersterTipp,
                                               const Spiel& spiel) const {
    if (ersterTipp > Spiel::AMOUNT_OF_HIDING_SPOTS)
        throw std::out_of_range{"ERROR: Tipp is out of range!\n"};
    const HidingSpotType emptySpot = spiel.emptySpot(ersterTipp);

    for (HidingSpotType i = 0; i < Spiel::AMOUNT_OF_HIDING_SPOTS; i++) {
        if (i != ersterTipp && i != emptySpot)
            return i;
    }
    throw std::logic_error{"ERROR: Could not find other spot to try!"};
}

#endif  // INCLUDE_GUARD_WECHSELNDERSPIELER_CPP
