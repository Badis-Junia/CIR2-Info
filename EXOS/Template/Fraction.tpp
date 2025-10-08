#include <stdexcept>

template<typename T>
Fraction<T>::Fraction() : num(0), den(1) {}

template<typename T>
Fraction<T>::Fraction(T num, T den) : num(num), den(den) {
    if (den == 0)
        throw std::invalid_argument("Le dénominateur ne peut pas être nul.");
    simplify();
}

template<typename T>
void Fraction<T>::simplify() {
    if (den < 0) {
        num = -num;
        den = -den;
    }
    T gcd = std::gcd(num, den);
    num /= gcd;
    den /= gcd;
}

// ---- Opérateurs arithmétiques ----

template<typename T>
Fraction<T> Fraction<T>::operator+(const Fraction& other) const {
    return Fraction(num * other.den + den * other.num, den * other.den);
}

template<typename T>
Fraction<T> Fraction<T>::operator-(const Fraction& other) const {
    return Fraction(num * other.den - den * other.num, den * other.den);
}

template<typename T>
Fraction<T> Fraction<T>::operator*(const Fraction& other) const {
    return Fraction(num * other.num, den * other.den);
}

template<typename T>
Fraction<T> Fraction<T>::operator/(const Fraction& other) const {
    if (other.num == 0)
        throw std::invalid_argument("Division par une fraction nulle.");
    return Fraction(num * other.den, den * other.num);
}

// ---- Opérateurs de comparaison ----

template<typename T>
bool Fraction<T>::operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
}

template<typename T>
bool Fraction<T>::operator!=(const Fraction& other) const {
    return !(*this == other);
}

template<typename T>
bool Fraction<T>::operator<(const Fraction& other) const {
    return num * other.den < other.num * den;
}

template<typename T>
bool Fraction<T>::operator>(const Fraction& other) const {
    return other < *this;
}

template<typename T>
bool Fraction<T>::operator<=(const Fraction& other) const {
    return !(*this > other);
}

template<typename T>
bool Fraction<T>::operator>=(const Fraction& other) const {
    return !(*this < other);
}

// ---- Utilitaires ----

template<typename T>
void Fraction<T>::print() const {
    std::cout << num << "/" << den;
}

template<typename T>
double Fraction<T>::toDouble() const {
    return static_cast<double>(num) / den;
}

