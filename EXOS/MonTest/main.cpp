#include <iostream>
#include "Fraction.hpp"

#include "Polygone.hpp"
int main() {

    Fraction test;
    Polygone testdeux;
    std::cin >> test;
    test.setnum(2);
    test.setden(1);
    std::cout << testdeux << std::endl;
    std::cout << test << std::endl;
    return 0;
}
