// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#ifndef INCLUDE_GUARD_SIMULATION_CPP
#define INCLUDE_GUARD_SIMULATION_CPP
#include "Simulation.hpp"

void Simulation::run(std::uint32_t rounds) {
    for (std::uint32_t i = 0; i < rounds; i++) {
        Spiel spiel;
        if (spiel.spiele(this->spieler))
            this->roundWon++;
        else
            this->roundLost++;
    }
}

double Simulation::getResult() const {
    if (this->roundWon == 0 && this->roundLost == 0)
        return 0;
    return static_cast<double>(this->roundWon) /
           (this->roundLost + this->roundWon);
}

#endif  // INCLUDE_GUARD_SIMULATION_CPP
