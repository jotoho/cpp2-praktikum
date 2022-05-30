// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include "./fahrzeug.cpp"

class LKW : Fahrzeug {
    const std::uint8_t achsenAnzahl;
    const std::uint16_t maxZuladungInTonnen;

    using Fahrzeug::Fahrzeug;

   public:
    LKW(const std::string& kennzeichen,
        const std::uint16_t jahrErstzulassung,
        const std::uint8_t achsenAnzahl,
        const std::uint16_t maxZuladungInTonnen)
        : Fahrzeug(kennzeichen, jahrErstzulassung),
          achsenAnzahl(achsenAnzahl),
          maxZuladungInTonnen(maxZuladungInTonnen) {}
};
