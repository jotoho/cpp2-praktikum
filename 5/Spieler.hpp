#ifndef INCLUDE_GUARD_SPIELER_HPP
#define INCLUDE_GUARD_SPIELER_HPP
#include "Spiel.hpp"

class Spiel;
class Spieler {
   public:
    virtual HidingSpotType ersterTipp() const;
    virtual HidingSpotType zweiterTipp(const HidingSpotType ersterTipp,
                                       const Spiel& spiel) const = 0;
};
#endif  // INCLUDE_GUARD_SPIELER_HPP
