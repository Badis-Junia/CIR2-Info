#include <iostream>
#include "Fraction.hpp"
#include <vector>
#include <algorithm>

int main() {
    // Fraction f1(1, 3);
    // Fraction f2(1, 3);



    // std::cout << "f1: "; 
    // f1.print();
    // std::cout << std::endl;
    
    // std::cout << "f2: "; 
    // f2.print();
    // std::cout << std::endl;
// ///////////////////////////////////////////////////////////////////    
    // Fraction f3 = f1 + f2;
    // std::cout << "f3 (f1 + f2): "; 
    // f3.print(); // somme
    // std::cout << std::endl;
// ///////////////////////////////////////////////////////////////////
    // Fraction f6 = f1 - f2;
    // std::cout << "f6 = (f1 - f2): "; 
    // f6.print(); // soustraction
    // std::cout << std::endl;
// ///////////////////////////////////////////////////////////////////
    // Fraction f7 = f1 * f2;
    // std::cout << "f6 = (f1 * f2): "; 
    // f7.print(); // soustraction
    // std::cout << std::endl;
// ///////////////////////////////////////////////////////////////////
    // Fraction f8 = f1 / f2;
    // std::cout << "f8 = (f1 / f2): "; 
    // f8.print(); // soustraction




    // std::cout << std::endl;





    std::vector<Fraction> tab;    
    long unsigned int nombre;

    std::cout << "Vous voulez combien de fois écrire dans le vecteur ? : ";
    std::cin >> nombre;
    Fraction value;
    for(long unsigned int i = 0;i<nombre;i++) {
        std::cin >> value;
        tab.push_back(value);   
    }


    std::sort(tab.begin(), tab.end());
    std::cout << std::endl;
    std::cout << "Voilà le tableau trié \n" << std::endl;    

    for(long unsigned int i = 0;i<tab.size();i++) {
        tab[i].print();
    }


    float total = 0;
    for(long unsigned int i = 0;i<tab.size();i++) {
        total+=tab[i].devenirentier();
    }
    std::cout << "La moyenne est " << total / tab.size() << std::endl;
    std::cout << "La somme est " << total << std::endl;
}
