// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include "./fahrzeug.cpp"

class PKW : Fahrzeug {
    const std::uint16_t hubraumCM{};
    const std::uint16_t leistungInKW{};

   public:
    enum class Schadstoffklasse : std::uint8_t {
        SCHADSTOFFARM = 0U,
        NORMAL = 1U,
        DIESEL = 2U
    };

   private:
    const Schadstoffklasse schadstoffeinordnung;

    using Fahrzeug::Fahrzeug;

   public:
    PKW(const std::string& kennzeichen,
        const std::uint16_t jahrErstzulassung,
        const std::uint16_t hubraumCM,
        const std::uint16_t leistungInKW,
        const Schadstoffklasse schadstoffeinordnung)
        : Fahrzeug(kennzeichen, jahrErstzulassung),
          hubraumCM(hubraumCM),
          leistungInKW(leistungInKW),
          schadstoffeinordnung(schadstoffeinordnung) {}
};
