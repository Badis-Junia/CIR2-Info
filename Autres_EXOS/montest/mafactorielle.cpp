#include <iostream>

int factorielle(int entier) {
    if(entier <= 1) {
        return 1;
    } else {
        return factorielle(entier - 1) * entier;
    }
}

int somme(int entier) {
    if(entier < 1) {
        return 0;
    } else {
        return somme(entier - 1) + entier;
    }
}

int main() {
    int masomme= 0;
    int entier = 5;
    std::cout << somme(5) << std::endl;
    for(int i = 1;i<=entier;i++) {
        masomme = masomme + i;
    }
    std::cout << masomme << std::endl;
    return 0;
}
