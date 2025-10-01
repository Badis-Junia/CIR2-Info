#include <iostream>
#include "Fraction.hpp"

int main() {
    Fraction f1(1, 3);
    Fraction f2(1, 3);



    std::cout << "f1: "; 
    f1.print();
    std::cout << std::endl;
    
    std::cout << "f2: "; 
    f2.print();
    std::cout << std::endl;
///////////////////////////////////////////////////////////////////    
    Fraction f3 = f1 + f2;
    std::cout << "f3 (f1 + f2): "; 
    f3.print(); // somme
    std::cout << std::endl;
///////////////////////////////////////////////////////////////////
    Fraction f6 = f1 - f2;
    std::cout << "f6 = (f1 - f2): "; 
    f6.print(); // soustraction
    std::cout << std::endl;
///////////////////////////////////////////////////////////////////
    Fraction f7 = f1 * f2;
    std::cout << "f6 = (f1 * f2): "; 
    f7.print(); // soustraction
    std::cout << std::endl;
///////////////////////////////////////////////////////////////////
    Fraction f8 = f1 / f2;
    std::cout << "f8 = (f1 / f2): "; 
    f8.print(); // soustraction
    std::cout << std::endl;
    
    
    return 0;
}
