#include <iostream>

int main() {
    int test;
    std::cout << "Entrez la valeur que vous voulez : ";
    std::cin >> test; 

    std::cout << "Voilà la table de multiplication du nombre " << test << std::endl;
    for(int i = 0;i<11;i++) {
        std::cout << test << "x" << i << "=" << test * i << "" << " " << std::endl;
    }

    return 0;
}
