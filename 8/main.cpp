// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include <cstdlib>
#include <iostream>
#include "./fraction.cpp"

template <typename T>
requires std::is_integral_v<T> && std::is_signed_v<T>
std::ostream& operator<<(
    std::ostream& out,
    const Fraction<T>& val) {
    out << "Fraction{" << val.getNominator() << ", " << val.getDenominator()
        << '}';
    return out;
}

class TestFractions {
    TestFractions() = delete;

   public:
    static void testConstructing(std::ostream& out) {
        out << "{5,5}: " << Fraction{5, 5} << '\n';
        out << "{10,2}: " << Fraction{10, 2} << '\n';
        out << "{15,16}: " << Fraction{15, 16} << '\n';
        out << "{0,1}: " << Fraction{0, 1} << '\n';

        {
            bool caughtIt = false;
            try {
                Fraction invalid{99, 0};
                out << "This fraction is illegal: " << invalid << '\n';
            } catch (const std::invalid_argument& e) {
                caughtIt = true;
            }

            if (!caughtIt)
                throw std::logic_error{
                    "Fraction illegally accepted 0 as denominator"};
        }
    }

    static void testOperators(std::ostream& out) {
        out << "3/6 + 7/10 = " << (Fraction{3, 6} + Fraction{7, 10}) << '\n';
        out << "9/4 + 13/7 = " << (Fraction{9, 4} + Fraction{13, 7}) << '\n';
    }
};

int main() {
    TestFractions::testConstructing(std::cout);
    TestFractions::testOperators(std::cout);
    return EXIT_SUCCESS;
}
