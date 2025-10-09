#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

template<typename T = int>
class Fraction {
private:
    T num;
    T den;

    void simplify();

public:
    Fraction();                    
    Fraction(T num, T den);        


    T getNum() const { return num; }
    T getDen() const { return den; }


    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;


    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;


    void print() const;
    double toDouble() const;


    Fraction plus(const Fraction& other) const { return *this + other; }
    Fraction minus(const Fraction& other) const { return *this - other; }
    Fraction times(const Fraction& other) const { return *this * other; }
    Fraction dividedBy(const Fraction& other) const { return *this / other; }


    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num << "/" << f.den;
    }
};

#include "Fraction.tpp"

#endif

