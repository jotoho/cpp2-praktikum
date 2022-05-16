#ifndef INCLUDE_GUARD_WECHSELNDERSPIELER_HPP
#define INCLUDE_GUARD_WECHSELNDERSPIELER_HPP
#include "Spieler.hpp"
class WechselnderSpieler : public Spieler {
   public:
    virtual HidingSpotType zweiterTipp(const HidingSpotType ersterTipp,
                                       const Spiel& spiel) const;
};
#endif  // INCLUDE_GUARD_WECHSELNDERSPIELER_HPP
