#include "Fraction.hpp"

int main() {
    Fraction<int> a(1, 2);
    Fraction<int> b(3, 4);

    Fraction<int> c = a + b;
    Fraction<int> d = a * b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << c << "\n";
    std::cout << "a * b = " << d << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
    std::cout << "Valeur décimale de a = " << a.toDouble() << "\n";

    return 0;
}

