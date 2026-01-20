#include <iostream>
#include "Animal.hpp"

int main() {

    Animal<int> montest;
    montest.setoiseau(3);
    std::cout << montest.getoiseau() << std::endl;
    montest.setoiseau(2);
    std::cout << montest.getoiseau() << std::endl;
    return 0;
}
