#ifndef INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_CPP
#define INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_CPP
#include "UnentschlossenerSpieler.hpp"
#include <stdexcept>
#include "SturerSpieler.hpp"
#include "WechselnderSpieler.hpp"

UnentschlossenerSpieler::UnentschlossenerSpieler(const double threshold)
    : threshold(threshold) {
    if (threshold > 1.0 || threshold < 0.0)
        throw std::out_of_range{"ERROR: Threshold out of range!\n"};
}

HidingSpotType UnentschlossenerSpieler::zweiterTipp(
    const HidingSpotType ersterTipp,
    const Spiel& spiel) const {
    if (ersterTipp > Spiel::AMOUNT_OF_HIDING_SPOTS)
        throw std::out_of_range{"ERROR: Tipp is out of range!\n"};
    const double random = static_cast<double>(std::rand()) / RAND_MAX;
    if (random >= threshold) {
        WechselnderSpieler spieler;
        return spieler.zweiterTipp(ersterTipp, spiel);
    } else {
        SturerSpieler spieler;
        return spieler.zweiterTipp(ersterTipp, spiel);
    }
}

#endif  // INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_CPP
