// étant donné que j'ai déjà réalisé la partie 5 et qu'on l'affiche, pas besoin de tout refaire 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

std::string genererNom(int tailleMinNomVille = 4, int tailleMaxNomVille = 10) {
    std::string result;
    int nbLettresNomVille = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille + 1);
    result.resize(nbLettresNomVille); 
    for(int i = 0; i < nbLettresNomVille; i++) {
        result[i] = (i == 0) ? 'A' + rand() % 26 : 'a' + rand() % 26;
    }
    return result;
}


std::map<std::string, std::tuple<int,int,int>> genererVilles(int nombre, int taille_carte) {
    std::map<std::string, std::tuple<int,int,int>> villes;
    for(int i = 0; i < nombre; i++) {
        int x = 1 + rand() % taille_carte;
        int y = 1 + rand() % taille_carte;
        std::string nom;
        do {
            nom = genererNom();
        } while (villes.count(nom)); 
        villes[nom] = std::make_tuple(i, x, y);
    }
    return villes;
}


std::vector<std::vector<int>> calculerDistances(const std::vector<std::string> &nomsVilles,
                                                const std::map<std::string, std::tuple<int,int,int>> &maMap) 
{
    int n = nomsVilles.size();
    std::vector<std::vector<int>> DIST(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        auto [id1, x1, y1] = maMap.at(nomsVilles[i]);
        for (int j = i + 1; j < n; j++) {
            auto [id2, x2, y2] = maMap.at(nomsVilles[j]);
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
    std::cout << "\n" << std::string(15 + 7*n, '-') << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << std::setw(15) << std::left << nomsVilles[i];
        for (int j = 0; j < n; j++)
            std::cout << std::setw(7) << std::left << DIST[i][j];
        std::cout << std::endl;
    }
}

int main() {
    constexpr int grainePourLeRand = 1;
    srand(grainePourLeRand); 

    
    auto villes = genererVilles(10, 100);

    
    std::vector<std::string> nomsVilles;
    for (const auto &[nom, _] : villes) nomsVilles.push_back(nom);
    std::sort(nomsVilles.begin(), nomsVilles.end());

    
    for (const auto &nom : nomsVilles) {
        auto [id, x, y] = villes[nom];
        std::cout << nom << " : (" << id << ", " << x << ", " << y << ")" << std::endl;
    }
    std::cout << std::endl;

    
    auto DIST = calculerDistances(nomsVilles, villes);
    afficherMatriceDistances(nomsVilles, DIST);

    return 0;
}

