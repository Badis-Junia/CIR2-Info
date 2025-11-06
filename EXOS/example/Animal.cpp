#include <iostream>
#include "Animal.hpp"
#include <string>

std::string Animal::getespece() {
    return this->espece;
}

void Animal::setespece(std::string espece) {
    this->espece = espece;
}

std::ostream& operator<<(std::ostream& flux, const Animal & animal) {
    flux << animal.espece << std::endl;
    return flux;
}

std::istream& operator>>(std::istream& flux, Animal & animal) {
    std::string test;
    flux >> test;
    return flux;
}
