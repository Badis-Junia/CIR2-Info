#include <iostream>
#include <vector>

void monotonie_max(std::vector<int>& T, int& deb, int& longueur) {
    int deb_courant = 0;
    int longueur_instant = 1;

    deb = 0;
    longueur = 1;

    for (long unsigned int i = 1; i < T.size(); i++) {
        if (T[i] > T[i - 1]) {
            longueur_instant++;
        } else {
            longueur_instant = 1;
            deb_courant = i;
        }

        if (longueur_instant > longueur) {
            longueur = longueur_instant;
            deb = deb_courant;
        }
    }
}

int main() {
    std::vector<int> T = {1, 5, 1, 8, 3, 8};

    int deb, lon;
    monotonie_max(T, deb, lon);

    std::cout << "Indice de depart : " << deb << std::endl;
    std::cout << "Longueur : " << lon << std::endl;

    return 0;
}
