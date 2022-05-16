#ifndef INCLUDE_GUARD_SPIEL_CPP
#define INCLUDE_GUARD_SPIEL_CPP
#include "Spiel.hpp"
#include <stdexcept>

bool Spiel::spiele(const Spieler& spieler) {
    const HidingSpotType ersterTipp = spieler.ersterTipp();
    const HidingSpotType zweiterTipp = spieler.zweiterTipp(ersterTipp, *this);
    return this->prizeLocation == zweiterTipp;
}

HidingSpotType Spiel::emptySpot(const HidingSpotType ersterTipp) const {
    if (ersterTipp > Spiel::AMOUNT_OF_HIDING_SPOTS)
        throw std::out_of_range{"ERROR: Tipp is out of range!\n"};
    for (HidingSpotType i = 0; i < Spiel::AMOUNT_OF_HIDING_SPOTS; i++) {
        if (i != ersterTipp && i != this->prizeLocation)
            return i;
    }
    throw std::logic_error{"ERROR: Could not find empty hiding spot!"};
}

#endif  // INCLUDE_GUARD_SPIEL_CPP
