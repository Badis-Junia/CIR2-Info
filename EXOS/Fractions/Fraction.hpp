#include <iostream>

class Fraction {
private:
    int num = 0;
    int den = 1;
    
public:
    Fraction(); 
    Fraction(int num, int den);  
    Fraction operator+(const Fraction &fraction);
    Fraction operator-(const Fraction &fraction);
    Fraction operator*(const Fraction &fraction);
    Fraction operator/(const Fraction &fraction);
    double devenirentier() const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    friend std::istream& operator>>(std::istream& in, Fraction& f);

    void print();
    Fraction plus(const Fraction &other);
    
    void setNum(int num) { 
        this->num = num; 
    }
    void setDen(int den) {
        this->den = den;
    }
};
