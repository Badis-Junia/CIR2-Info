#include <iostream>
#include "Fraction.hpp"

void Fraction::setden(int value) {
    this->den = value;
}

void Fraction::setnum(int value) {
    this->num = value;
}



std::ostream& operator<<(std::ostream& flux, const Fraction &fraction) {
    flux << fraction.num << "/" << fraction.den << std::endl;
    return flux;
}

std::istream& operator>>(std::istream& flux,const Fraction &fraction) {
    char slash;
    flux >> fraction.num >> slash >> fraction.den;
    return flux;
}
