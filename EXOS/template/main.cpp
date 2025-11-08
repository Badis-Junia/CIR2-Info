#include <iostream>
#include "Animal.hpp"

template<typename T>
void test(T oiseau) {
    std::cout << oiseau << std::endl;
}

int main() {
    Oiseau<float> cheval;
    cheval.setoiseau(2.5);
    std::cout << cheval.getoiseau() << std::endl;
    cheval.setoiseau(4.4);
    std::cout << cheval.getoiseau() << std::endl;
    test(3);
    return 0;
}

