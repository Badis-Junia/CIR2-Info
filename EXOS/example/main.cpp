#include <iostream>
#include "Animal.hpp"

int main() {
    Animal test;
    std::string monespece;
    std::cout << "Entrez l'animal : ";
    std::cin >> monespece;
    test.setespece(monespece);
    std::cout << test << std::endl;
}

