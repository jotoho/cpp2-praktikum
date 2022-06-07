// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include <cmath>
#include <concepts>
#include <stdexcept>

template <typename T>
requires std::is_integral_v<T>&& std::is_signed_v<T> class Fraction {
   private:
    T nominator;
    T denominator;

    constexpr static T ggT(const T a, const T b) {
        if (a == 0 && a == 0)
            return 0;
        else if (b == 0)
            return std::abs(a);
        else if (a == 0)
            return std::abs(b);
        else {
            const T rest = a % b;
            return std::abs(ggT(b, rest));
        }
    }

    void normalize() {
        if (denominator == 0) {
            throw std::invalid_argument{"Cannot divide by zero"};
        } else if (denominator < 0) {
            this->nominator *= -1;
            this->denominator *= -1;
        }

        const auto sharedDivisor = Fraction::ggT(nominator, denominator);
        this->nominator /= sharedDivisor;
        this->denominator /= sharedDivisor;
    }

   public:
    Fraction(const T nominator, const T denominator)
        : nominator(nominator), denominator(denominator) {
        this->normalize();
    }

    Fraction operator-() const {
        return Fraction{-(this->nominator), this->denominator};
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction{this->nominator + other.nominator,
                        this->denominator + other.denominator};
    }

    Fraction operator-(const Fraction& other) const {
        return (*this) + (-other);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction{this->nominator * other.nominator,
                        this->denominator * other.denominator};
    }

    Fraction operator/(const Fraction& other) const {
        return (*this) * (Fraction{other.denominator, other.nominator});
    }

    T getNominator() const { return this->nominator; }

    T getDenominator() const { return this->denominator; }

    double toDouble() const {
        return static_cast<double>(this->nominator) /
               static_cast<double>(this->denominator);
    }
};
