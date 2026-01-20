#include <iostream>
#include <string>
#include <vector>

std::string genererNom(int tailleMinNomVille = 4, int tailleMaxNomVille = 10) {
    std::string result;
    int nbLettresNomVille = tailleMinNomVille + rand()%(tailleMaxNomVille-tailleMinNomVille+1);
    result.resize(nbLettresNomVille); 
    for(int i = 0;i<nbLettresNomVille;i++) {
            if(i == 0) {
                result[0] = 'A' + rand()% 26;
            } else {
                result[i] = 'a' + rand()% 26;
            }
    }
    return result;
}

std::vector<std::string> remplirVectorVille(int nombre) {
    std::vector<std::string> result;
    for(int i = 0;i<nombre;i++) {
        result.push_back(genererNom());
    }
    return result;
}

void afficherVector(std::vector<std::string> monvector) {
    for(const std::string& elem : monvector) {
        std::cout << elem << " ";
    }
}


int main() {
    constexpr int grainePourLeRand = 1;
    srand(grainePourLeRand); 


    std::cout << genererNom() << std::endl;
    std::vector<std::string> vectorville = remplirVectorVille(10);


    return 0;
}

