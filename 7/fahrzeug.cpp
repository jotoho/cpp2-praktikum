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
