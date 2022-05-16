// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#ifndef INCLUDE_GUARD_SPIELER_CPP
#define INCLUDE_GUARD_SPIELER_CPP
#include "Spieler.hpp"

HidingSpotType Spieler::ersterTipp() const {
    return std::rand() % Spiel::AMOUNT_OF_HIDING_SPOTS;
}

#endif  // INCLUDE_GUARD_SPIELER_CPP
