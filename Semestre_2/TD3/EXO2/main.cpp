#include <iostream>
#include <string>
#include <vector> 

void toutesLesPermutations(std::vector<std::string> &vectorville, int debut, int fin, int &compteur) {
    if (debut == fin) {
        std::cout << compteur << " : ";
        for(const std::string &elem : vectorville ) {
            std::cout << " " << elem;
        }
        std::cout << std::endl;
        compteur++;
    } else {
        for (int i = debut; i <= fin; i++) {
            std::swap(vectorville[debut],vectorville[i]);
            toutesLesPermutations(vectorville, debut + 1, fin, compteur);
            std::swap(vectorville[debut],vectorville[i]);
        }
    }
}

int main() {
    int compteur = 1; 
    std::vector<std::string> vecteurDeNomDeVilles;
    vecteurDeNomDeVilles.push_back("Lille");
    vecteurDeNomDeVilles.push_back("Vda");
    toutesLesPermutations(vecteurDeNomDeVilles, 0, vecteurDeNomDeVilles.size() - 1, compteur);
    return 0;
}

