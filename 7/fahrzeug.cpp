// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include <cstddef>
#include <string>

class Fahrzeug {
    const std::string kennzeichen;
    const std::uint16_t jahrErstzulassung{};

   public:
    Fahrzeug(const std::string& kennzeichen,
             const std::uint16_t jahrDerErstzulassung)
        : kennzeichen(kennzeichen), jahrErstzulassung(jahrDerErstzulassung) {}
};
