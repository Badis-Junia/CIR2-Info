#include <iostream>
#include "Fraction.hpp"
#include <vector>
int main() {

    Fraction test;
    std::cin >> test;
    test.setnum(2);
    test.setden(1);

    std::cout << test << std::endl;
    return 0;
}
