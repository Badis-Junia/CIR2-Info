#include <iostream>
#include <string>
#include <vector>
#include <map>

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

auto remplirVectorVille_Position(int nombre, int taille_carte) {
    std::vector<std::map<std::string, std::tuple<int,int,int>>> result;
    std::map<std::string, std::tuple<int,int,int>> test;
    result.resize(nombre); 
    for(int i = 0;i<nombre;i++) {
        int x = 1 + rand()%taille_carte;
        int y = 1 + rand()%taille_carte;
        std::tuple<int,int,int> monTuple = std::make_tuple(i, x, y);
        std::map<std::string, std::tuple<int,int,int>> test;
        test[genererNom()] = monTuple;
        result[i] = test;
    }
    return result;
}



int main() {

    constexpr int grainePourLeRand = 1;
    srand(grainePourLeRand); 

    std::vector<std::map<std::string, std::tuple<int,int,int>>> vectorville = remplirVectorVille_Position(10, 100);

    for(size_t i = 0; i < vectorville.size(); i++) {
        for(const auto& [nom, infos] : vectorville[i]) {
            int id, x, y;
            std::tie(id, x, y) = infos;
            std::cout << nom << " : "<< " (" << id << ", "<<  x << ", " << y << ")" << std::endl;
        }
    }

    return 0;
}


