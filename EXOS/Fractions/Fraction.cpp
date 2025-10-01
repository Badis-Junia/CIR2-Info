#include <iostream>
#include "Fraction.hpp"


Fraction::Fraction() : num(0), den(1) {}


Fraction::Fraction(int num, int den) : num(num), den(den) {}

Fraction Fraction::operator+(const Fraction &fraction) {
    Fraction result;
    result.num = this->num * fraction.den + this->den * fraction.num;
    result.den = this->den * fraction.den;
    return result;
}

Fraction Fraction::operator-(const Fraction &fraction) {
    Fraction result;
    result.num = this->num * fraction.den - this->den * fraction.num;
    result.den = this->den * fraction.den;
    return result;
}


void Fraction::print() {
    std::cout << num << "/" << den;
}

Fraction Fraction::plus(const Fraction &other) {
    return *this + other;
}

