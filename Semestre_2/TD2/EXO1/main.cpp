#include <iostream>
#include <array>

bool est_premier(int n) {
    if (n <= 1) {
        std::cerr << "Il faut prendre un entier naturel positif." << std::endl;
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void generer_premier(int n) {
    int i = 2;
    int compteur_pour_tableau = 0;
    std::array<int, 1000> liste_nombre_entiers_premiers;
    if(n <= 1000) {
        std::cout << "Prenez un entier supérieur à 1000" << std::endl;
    }
    while(i < n) {
        if(est_premier(i)) {
            std::cout << i << std::endl;
            liste_nombre_entiers_premiers[compteur_pour_tableau] = i;

        }
        compteur_pour_tableau++;
        i++;
    }
}
int main() {
    std::cout << est_premier(5) << std::endl; 
    generer_premier(1010);
    return 0;
}
