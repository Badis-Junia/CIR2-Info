#include "Polygone.hpp"
#include <iostream>

int Polygone::getcote() {
    return this->cote;
}


void Polygone::setcote(int value) {
    this->cote = value;
}

int Carre::getperimetre() {
    return this->cote * 4;
}

std::ostream& operator<<(std::ostream& flux, const Polygone & monpoly) {
    flux << monpoly.cote << std::endl; 
    return flux;
}
