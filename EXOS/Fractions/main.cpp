#include <iostream>
#include "Fraction.hpp"

int main() {
    Fraction f1(1, 3);
    Fraction f2(1, 3);

    Fraction f3 = f1 + f2;

    std::cout << "f1: "; 
    f1.print();
    std::cout << std::endl;
    
    std::cout << "f2: "; 
    f2.print();
    std::cout << std::endl;
    
    std::cout << "f3 (f1 + f2): "; 
    f3.print();
    std::cout << std::endl;

    Fraction f4(1, 3);
    Fraction f5(1, 3);



    Fraction f6 = f4 - f5;
    std::cout << "f6 = (f4 + f5): "; 
    f6.print();
    std::cout << std::endl;
    
    return 0;
}
