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

Fraction Fraction::operator*(const Fraction &fraction) {
    Fraction result;
    result.num = this->num * fraction.num;
    result.den = this->den * fraction.den;
    return result;
}

Fraction Fraction::operator/(const Fraction &fraction) {
    Fraction result;
    result.num = this->num * fraction.den;
    result.den = this->den * fraction.num;
    return result;
}


void Fraction::print() {
    std::cout << num << "/" << den << std::endl;
}

Fraction Fraction::plus(const Fraction &other) {
    return *this + other;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    char slash;
    in >> f.num >> slash >> f.den; // par exemple pour lire "3/4"
    return in;
}

bool Fraction::operator<(const Fraction& other) const {
    return (num * other.den) < (other.num * den);
}

bool Fraction::operator>(const Fraction& other) const {
    return (num * other.den) > (other.num * den);
}

double Fraction::devenirentier() const {
    return double(num) / double(den);
}

