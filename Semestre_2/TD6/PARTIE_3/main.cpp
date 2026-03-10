#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <random>
#include <iomanip>

using Matrice = std::vector<std::vector<int>>;
int infini = INT_MAX;

bool parcoursLargeur(const std::vector<std::vector<int>>& grapheResiduel, int s, int t, std::vector<int>& predecesseurCheminAmeliorant) {
    int nbSommets = grapheResiduel.size();
    std::vector<bool> sommetVisite(nbSommets, false);
    std::queue<int> file;

    file.push(s);
    sommetVisite[s] = true;
    predecesseurCheminAmeliorant[s] = -1;
    
    while (!file.empty()) {
        int u = file.front();
        file.pop();
        for (int v = 0; v < nbSommets; v++) {
            if (!sommetVisite[v] && grapheResiduel[u][v] > 0) {
                file.push(v);
                predecesseurCheminAmeliorant[v] = u;
                sommetVisite[v] = true;
            }
        }
    }
    return sommetVisite[t];
}

int fordFulkerson(Matrice& capacites, int s, int t) {
    int n = capacites.size();
    Matrice residuel = capacites;
    std::vector<int> predecesseur(n);
    int flot_max = 0;

    while (parcoursLargeur(residuel, s, t, predecesseur)) {
        int augmentation = infini;
        for (int v = t; v != s; v = predecesseur[v]) {
            int u = predecesseur[v];
            augmentation = std::min(augmentation, residuel[u][v]);
        }
        for (int v = t; v != s; v = predecesseur[v]) {
            int u = predecesseur[v];
            residuel[u][v] -= augmentation;
            residuel[v][u] += augmentation;
        }
        flot_max += augmentation;
    }
    return flot_max;
}

void afficherMatrice(const Matrice& mat, const std::string& nom) {
    std::cout << nom << ":\n";
    for (long unsigned int i = 0; i < mat.size(); ++i) {
        for (long unsigned int j = 0; j < mat.size(); ++j) {
            if (mat[i][j] == infini) {
                std::cout << "INF ";
            } else {
                std::cout << mat[i][j] << " ";
            }         
        }
        std::cout << std::endl;
    }
}

void partie3_etape1() {
    std::cout << "PARTIE 3 Modèle et algorithme adaptés à un cas concret : optimisation de la production de chocolat" << std::endl;
    std::cout << std::endl;
    std::cout << "  Partie 3.1 : Production libre\n";
    const int S = 0;
    const int U2 = 1;
    const int U3 = 2;
    const int U4 = 3;
    const int T = 4;
    
    Matrice cap(5, std::vector<int>(5, 0));

    cap[S][U2] = infini;
    cap[S][U3] = infini;
    cap[S][U4] = infini;

    cap[U2][T] = 19;
    cap[U3][T] = 7;
    cap[U4][T] = 5;

    int flot = fordFulkerson(cap, S, T);
    std::cout << "   > Flot maximal = " << flot << std::endl;
}

void partie3_etape2() {
    std::cout << "  Partie 3.2 : Production limitée\n";
    const int S = 0;
    const int U2 = 1;
    const int U3 = 2;
    const int U4 = 3;
    const int T = 4;

    Matrice cap(5, std::vector<int>(5, 0));

    cap[S][U2] = 25;
    cap[S][U3] = 10;
    cap[S][U4] = 8;

    cap[U2][T] = 19;
    cap[U3][T] = 7;
    cap[U4][T] = 5;

    int flot = fordFulkerson(cap, S, T);
    std::cout << "   > Flot maximal = " << flot << std::endl;
}

void partie3_etape3() {
    std::cout << "  Partie 3.3 : Production et transferts limités" << std::endl;
    
    const int S = 0; // Source (S)
    const int U2 = 1; // Usine 2 (France)
    const int U3 = 2; // Usine 3 (Belgique)
    const int U4 = 3; // Usine 4 (Suisse)
    const int T = 4; // Puits (T)
    
    Matrice cap(5, std::vector<int>(5, 0));

    // Capacités de production (de la source vers les usines)
    cap[S][U2] = 25;  // CapProd(2) == 25
    cap[S][U3] = 10;  // CapProd(3) == 10
    cap[S][U4] = 8;   // CapProd(4) == 8

    // Demandes locales (des usines vers le puits)
    cap[U2][T] = 30;  // Dem(2) == 30
    cap[U3][T] = 7;   // Dem(3) == 7
    cap[U4][T] = 5;   // Dem(4) == 5

    // Capacités de transfert entre usines
    cap[U2][U3] = 8;   // CapTrans(2>3) == 8
    cap[U3][U2] = 8;   // CapTrans(3>2) == 8
    cap[U2][U4] = 12;  // CapTrans(2>4) == 12
    cap[U4][U2] = 12;  // CapTrans(4>2) == 12
    cap[U3][U4] = 3;   // CapTrans(3>4) == 3
    cap[U4][U3] = 3;   // CapTrans(4>3) == 3
    
    int flot = fordFulkerson(cap, S, T);
    std::cout << "  > Flot maximal satisfaisant la demande = " << flot << std::endl;
    
    // Calcul de la demande totale
    int demande_totale = cap[U2][T] + cap[U3][T] + cap[U4][T];
    std::cout << "  > Demande totale = " << demande_totale << std::endl;
    
    if (flot >= demande_totale) {
        std::cout << "  > La demande totale peut être satisfaite !" << std::endl;
    } else {
        std::cout << "  > La demande totale ne peut pas être satisfaite (limitation par production ou transferts)" << std::endl;
    }
    
    int prod_totale = cap[S][U2] + cap[S][U3] + cap[S][U4];
    std::cout << "    Production totale disponible: " << prod_totale << std::endl;
    
    if (prod_totale < demande_totale) {
        std::cout << "    -> La production totale (" << prod_totale << ") est inférieure à la demande (" 
                  << demande_totale << ")" << std::endl;
    }
    
    std::cout << "    Contraintes de transfert:" << std::endl;
    std::cout << "      France (U2) peut envoyer: " << cap[U2][U3] << " vers Belgique, " 
              << cap[U2][U4] << " vers Suisse" << std::endl;
    std::cout << "      Belgique (U3) peut envoyer: " << cap[U3][U2] << " vers France, " 
              << cap[U3][U4] << " vers Suisse" << std::endl;
    std::cout << "      Suisse (U4) peut envoyer: " << cap[U4][U2] << " vers France, " 
              << cap[U4][U3] << " vers Belgique" << std::endl;
}

void partie3_etape5_premier_code() {
    std::cout << "  Partie 3.4 Premier Code : Demande aléatoire" << std::endl;
    const int S = 0;
    const int U2 = 1;
    const int U3 = 2;
    const int U4 = 3;
    const int T = 4;
    

    // Usine 2 (France) : entre 15 et 35
    // Usine 3 (Belgique) : entre 5 et 15
    // Usine 4 (Suisse) : entre 3 et 12
    
    std::mt19937 gen(22222222);
    std::uniform_int_distribution<> distU2(15, 35);
    std::uniform_int_distribution<> distU3(5, 15);
    std::uniform_int_distribution<> distU4(3, 12);
    
    Matrice cap(5, std::vector<int>(5, 0));

    // Capacités de production fixes
    cap[S][U2] = 25;
    cap[S][U3] = 10;
    cap[S][U4] = 8;

    // Demandes aléatoires
    cap[U2][T] = distU2(gen);
    cap[U3][T] = distU3(gen);
    cap[U4][T] = distU4(gen);

    // Capacités de transfert fixes
    cap[U2][U3] = 8;
    cap[U3][U2] = 8;
    cap[U2][U4] = 12;
    cap[U4][U2] = 12;
    cap[U3][U4] = 3;
    cap[U4][U3] = 3;
    
    std::cout << "   > Demandes générées aléatoirement :" << std::endl;
    std::cout << "      Usine 2 (France)   : " << cap[U2][T] << " (bornes : 15-35)" << std::endl;
    std::cout << "      Usine 3 (Belgique) : " << cap[U3][T] << " (bornes : 5-15)" << std::endl;
    std::cout << "      Usine 4 (Suisse)   : " << cap[U4][T] << " (bornes : 3-12)" << std::endl;
    
    int flot = fordFulkerson(cap, S, T);
    int demande_totale = cap[U2][T] + cap[U3][T] + cap[U4][T];
    double pourcentage = (static_cast<double>(flot) / demande_totale) * 100;
    
    std::cout << "   > Résultats :" << std::endl;
    std::cout << "      Demande totale : " << demande_totale << std::endl;
    std::cout << "      Flot maximal   : " << flot << std::endl;
    std::cout << "      Pourcentage satisfait : " << std::fixed << std::setprecision(1) << pourcentage << "%" << std::endl;
}

void partie3_etape5_deuxieme_code() {
    std::cout << "  Partie 3.4 Deuxieme Code : Simulation annuelle (12 mois)" << std::endl;
    
    const int S = 0;
    const int U2 = 1;
    const int U3 = 2;
    const int U4 = 3;
    const int T = 4;
    
    // Bornes pour chaque demande
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distU2(15, 35);
    std::uniform_int_distribution<> distU3(5, 15);
    std::uniform_int_distribution<> distU4(3, 12);
    
    int demande_totale_annuelle = 0;
    int flot_total_annuel = 0;
    std::cout << "    |------|-----------------------|----------------|----------|-------------|" << std::endl;    
    std::cout << "    | Mois | Demandes (U2, U3, U4) | Demande totale | Flot max | % satisfait |" << std::endl;
    std::cout << "    |------|-----------------------|----------------|----------|-------------|" << std::endl;
    
    for (int mois = 1; mois <= 12; mois++) {
        Matrice cap(5, std::vector<int>(5, 0));

        // Capacités de production fixes
        cap[S][U2] = 25;
        cap[S][U3] = 10;
        cap[S][U4] = 8;

        // Demandes aléatoires
        int d2 = distU2(gen);
        int d3 = distU3(gen);
        int d4 = distU4(gen);
        
        cap[U2][T] = d2;
        cap[U3][T] = d3;
        cap[U4][T] = d4;

        // Capacités de transfert fixes
        cap[U2][U3] = 8;
        cap[U3][U2] = 8;
        cap[U2][U4] = 12;
        cap[U4][U2] = 12;
        cap[U3][U4] = 3;
        cap[U4][U3] = 3;
        
        int flot = fordFulkerson(cap, S, T);
        int demande_totale = d2 + d3 + d4;
        double pourcentage = (static_cast<double>(flot) / demande_totale) * 100;
        
        demande_totale_annuelle += demande_totale;
        flot_total_annuel += flot;
        
        std::cout << "    | " << std::setw(2)  << mois << "   | "
                  << std::setw(4) << d2 << ", " 
                  << std::setw(4) << d3 << ", " 
                  << std::setw(4) << d4 << "      | "
                  << std::setw(6) << demande_totale << "         | "
                  << std::setw(5) << flot << "    | "
                  << std::fixed << std::setprecision(1) << std::setw(6) << pourcentage << "%" << "     | " << std::endl;
    std::cout << "    |------|-----------------------|----------------|----------|-------------|" << std::endl;
    }
    
    double pourcentage_annuel = (static_cast<double>(flot_total_annuel) / demande_totale_annuelle) * 100;
    
    std::cout << "\n  Résultats annuels :" << std::endl;
    std::cout << "    Demande totale sur l'année : " << demande_totale_annuelle << std::endl;
    std::cout << "    Flot total sur l'année      : " << flot_total_annuel << std::endl;
    std::cout << "    Pourcentage satisfait sur l'année : " 
              << std::fixed << std::setprecision(1) << pourcentage_annuel << "%" << std::endl;
}

int main() {
    partie3_etape1();
    std::cout << std::endl;
    partie3_etape2();
    std::cout << std::endl;
    partie3_etape3();
    std::cout << std::endl;
    partie3_etape5_premier_code();
    std::cout << std::endl;
    partie3_etape5_deuxieme_code();
    
    return 0;
}