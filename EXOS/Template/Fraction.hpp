#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric> // pour std::gcd

template<typename T = int>
class Fraction {
private:
    T num;
    T den;

    void simplify();

public:
    Fraction();                          // Constructeur par défaut
    Fraction(T num, T den);              // Constructeur paramétré

    // Getters
    T getNum() const { return num; }
    T getDen() const { return den; }

    // Opérateurs arithmétiques
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Opérateurs de comparaison
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    // Méthodes utilitaires
    void print() const;
    double toDouble() const;

    // Méthodes "nommées"
    Fraction plus(const Fraction& other) const { return *this + other; }
    Fraction minus(const Fraction& other) const { return *this - other; }
    Fraction times(const Fraction& other) const { return *this * other; }
    Fraction dividedBy(const Fraction& other) const { return *this / other; }

    // Ami pour permettre `std::cout << fraction`
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num << "/" << f.den;
    }
};

#include "Fraction.tpp" // inclusion du template

#endif // FRACTION_HPP

