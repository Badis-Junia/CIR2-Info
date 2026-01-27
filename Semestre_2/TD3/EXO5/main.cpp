#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>
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


std::vector<std::vector<int>> calculerDistances(
    const std::vector<std::string> &nomsVilles,
    const std::map<std::string, std::tuple<int,int,int>> &maMap) 
{
    int n = nomsVilles.size();
    std::vector<std::vector<int>> DIST(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        auto [index1, x1, y1] = maMap.at(nomsVilles[i]);
        for (int j = i+1; j < n; j++) {
            auto [index2, x2, y2] = maMap.at(nomsVilles[j]);
            int distance = static_cast<int>(std::round(std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))));
            DIST[i][j] = distance;
            DIST[j][i] = distance;
        }
    }
    return DIST;
}

void afficherMatriceDistances(const std::vector<std::string> &nomsVilles,
                             const std::vector<std::vector<int>> &DIST) {
    int n = nomsVilles.size();
    std::cout << std::setw(15) << std::left << "";
    for (int i = 0; i < n; i++)
        std::cout << std::setw(7) << std::left << nomsVilles[i];
    std::cout << std::endl;
    std::cout << std::string(15 + 7*n, '-') << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(15) << std::left << nomsVilles[i];
        for (int j = 0; j < n; j++)
            std::cout << std::setw(7) << std::left << DIST[i][j];
        std::cout << std::endl;
    }
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



