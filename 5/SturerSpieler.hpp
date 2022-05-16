// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#ifndef INCLUDE_GUARD_STURERSPIELER_HPP
#define INCLUDE_GUARD_STURERSPIELER_HPP
#include "Spieler.hpp"

class SturerSpieler : public Spieler {
   public:
    virtual HidingSpotType zweiterTipp(const HidingSpotType ersterTipp,
                                       const Spiel& spiel) const;
};

#endif  // INCLUDE_GUARD_STURERSPIELER_HPP
