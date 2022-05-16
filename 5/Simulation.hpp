#ifndef INCLUDE_GUARD_SIMULATION_HPP
#define INCLUDE_GUARD_SIMULATION_HPP
#include <cinttypes>
#include "Spieler.hpp"

class Simulation {
   private:
    const Spieler& spieler;
    std::uint32_t roundLost = 0;
    std::uint32_t roundWon = 0;

   public:
    Simulation() = delete;
    Simulation(const Spieler& spieler) : spieler(spieler) {}
    void run(std::uint32_t rounds);
    double getResult() const;
};
#endif  // INCLUDE_GUARD_SIMULATION_HPP
