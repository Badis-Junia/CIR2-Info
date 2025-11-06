#include "Polygone.hpp"

int Polygone::getcote() {
    return this->cote;
}


void Polygone::setcote(int value) {
    this->cote = value;
}

int Carre::getperimetre() {
    return this->cote * 4;
}
