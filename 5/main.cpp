// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Simulation.hpp"
#include "SturerSpieler.hpp"
#include "UnentschlossenerSpieler.hpp"
#include "WechselnderSpieler.hpp"

void testSpieler(Spieler& spieler, std::ostream& out) {
    Simulation sim{spieler};
    sim.run(1000000);
    out << sim.getResult() * 100 << "% Successrate" << std::endl;
}

int main() {
    std::srand(std::time(nullptr));

    {
        std::cout << "\nSturer Spieler\n";
        SturerSpieler spieler;
        testSpieler(spieler, std::cout);
    }

    {
        std::cout << "\nWechselnder Spieler\n";
        WechselnderSpieler spieler;
        testSpieler(spieler, std::cout);
    }

    {
        std::cout << "\nUnentschlossener Spieler\n";
        UnentschlossenerSpieler spieler{0.5};
        testSpieler(spieler, std::cout);
    }
}
