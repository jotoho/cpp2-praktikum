#ifndef INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_HPP
#define INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_HPP
#include "Spieler.hpp"

class UnentschlossenerSpieler : public Spieler {
    const double threshold;

   public:
    UnentschlossenerSpieler() = delete;
    UnentschlossenerSpieler(const double threshold);
    virtual HidingSpotType zweiterTipp(const HidingSpotType ersterTipp,
                                       const Spiel& spiel) const;
};
#endif  // INCLUDE_GUARD_UNENTSCHLOSSENERSPIELER_HPP
