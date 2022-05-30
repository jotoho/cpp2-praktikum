// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include "./fahrzeug.cpp"

class Motorrad : Fahrzeug {
    const std::uint16_t hubraumCM;

    using Fahrzeug::Fahrzeug;

   public:
    Motorrad(const std::string& kennzeichen,
             const std::uint16_t jahrErstzulassung,
             const std::uint16_t hubraumCM)
        : Fahrzeug(kennzeichen, jahrErstzulassung), hubraumCM(hubraumCM) {}
};
