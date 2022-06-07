#include <cstdlib>
#include "./fraction.cpp"

class TestFractions {
    TestFractions() = delete;

   public:
    static void testConstructing() {
        {
            [[maybe_unused]] Fraction a{5, 5};
            [[maybe_unused]] Fraction b{10, 2};
            [[maybe_unused]] Fraction c{15, 16};
        }

        {
            bool caughtIt = false;
            try {
                [[maybe_unused]] Fraction d{99, 0};
            } catch (const std::invalid_argument& e) {
                caughtIt = true;
            }

            if (!caughtIt)
                throw std::logic_error{
                    "Fraction illegally accepted 0 as denominator"};
        }
    }

    static void testOperators() {
        Fraction{3, 6} + Fraction{7, 10};
        Fraction{9, 4} + Fraction{13, 7};
    }
};

int main() {
    TestFractions::testConstructing();
    TestFractions::testOperators();
    return EXIT_SUCCESS;
}
