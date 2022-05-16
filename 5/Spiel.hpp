#ifndef INCLUDE_GUARD_SPIEL_HPP
#define INCLUDE_GUARD_SPIEL_HPP
#include <cinttypes>
#include <cstdlib>
using HidingSpotType = std::uint8_t;
#include "Spieler.hpp"

class Spieler;
class Spiel {
   public:
    constexpr static HidingSpotType AMOUNT_OF_HIDING_SPOTS = 3;

   private:
    const HidingSpotType prizeLocation = std::rand() % AMOUNT_OF_HIDING_SPOTS;

   public:
    bool spiele(const Spieler& spieler);
    HidingSpotType emptySpot(const HidingSpotType ersterTipp) const;
};
#endif  // INCLUDE_GUARD_SPIEL_HPP
