#include "Suite.hpp"
#include <iostream>

Suite_arithmetique::Suite_arithmetique() {
    this->raison = 0;
    this->terme_initial = 0;
}

Suite_geometrique::Suite_geometrique() {
    this->raison = 0;
    this->terme_initial = 0;
}

Suite_arithmetique::Suite_arithmetique(int debut, int maraison) {
    this->raison = debut;
    this->terme_initial = maraison;
}

Suite_geometrique::Suite_geometrique(int debut, int maraison) {
    this->raison = debut;
    this->terme_initial = maraison;
}


std::ostream& operator<<(std::ostream & flux, const Suite& masuite) {
    flux << "Un = " << masuite.terme_initial << "x" << masuite.raison << std::endl;
    return flux;
}

std::istream& operator>>(std::istream & flux, Suite& masuite) {
    char foix;
    std::string suite;
    flux >> suite >> masuite.terme_initial >> foix >> masuite.raison;
    return flux;
}
