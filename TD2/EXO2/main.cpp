#include <iostream>
#include <iomanip>

int main() {
    int test;
    std::cout << "Entrez la valeur que vous voulez : ";
    std::cin >> test; 


    std::cout << std::setw(5) << "i" << std::setw(3) << "|" 
              << std::setw(5) << test << " x  i" << std::setw(3) << "|" 
              << std::setw(10) << "  Résultat" << std::endl;

    
    for(int i = 0; i < 11; i++) {
        std::cout << std::setw(5) << i << std::setw(3) << "|" 
                  << std::setw(5) << test << " x " << std::setw(2) << i << std::setw(3) << "|" 
                  << std::setw(10) << test * i << std::endl;
    }

    return 0;
}

