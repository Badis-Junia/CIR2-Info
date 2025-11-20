#include <iostream>
#include "Fraction.hpp"
#include <vector>
#include <algorithm>

int main() {

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
    Fraction mafraction(1, 0);

    std::cout << mafraction.devenirentier() << std::endl;

}
