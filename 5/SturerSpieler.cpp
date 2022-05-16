#ifndef INCLUDE_GUARD_STURERSPIELER_CPP
#define INCLUDE_GUARD_STURERSPIELER_CPP
#include "SturerSpieler.hpp"
#include <stdexcept>

HidingSpotType SturerSpieler::zweiterTipp(
    const HidingSpotType ersterTipp,
    [[maybe_unused]] const Spiel& spiel) const {
    if (ersterTipp > Spiel::AMOUNT_OF_HIDING_SPOTS)
        throw std::out_of_range{"ERROR: Tipp is out of range!\n"};
    return ersterTipp;
}
#endif  // INCLUDE_GUARD_STURERSPIELER_CPP
