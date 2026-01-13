#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <queue>

#include <map>
#include <set>

#include <chrono>


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


void generer_premier_equipe_1(int n, int nombre_tour) {
    int i = 2;
    auto debut = std::chrono::high_resolution_clock::now();
    std::array<int, 1000> array_nombre_entiers_premiers;
    std::vector<int> vector_nombre_entiers_premiers;
    std::list<int> liste_nombre_entiers_premiers;
    std::queue<int> queue_nombre_entiers_premiers;
    int compteur_pour_tableau = 0;
    if(n <= 1000) {
        std::cout << "Prenez un entier supérieur à 1000" << std::endl;
    }
    while(i < n) {
        if(est_premier(i)) {
            for(int i =0;i<nombre_tour;i++) {
                vector_nombre_entiers_premiers.push_back(i);
                array_nombre_entiers_premiers[compteur_pour_tableau] = i;
                liste_nombre_entiers_premiers.push_back(i);
                queue_nombre_entiers_premiers.push(i);
            }
        }
        compteur_pour_tableau++;
        i++;
    }
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duree = fin - debut;
    std::cout << "Temps écoulé pour la première équipe : " << duree.count() << " secondes\n";
}

void generer_premier_equipe_2(int n, int nombre_tour) {
    if (n <= 1000) {
        std::cout << "Prenez un entier supérieur à 1000\n";
        return;
    }

    auto debut = std::chrono::high_resolution_clock::now();

    std::map<int, int> map_premiers;        
    std::multimap<int, int> multimap_premiers;
    std::set<int> set_premiers;              
    std::multiset<int> multiset_premiers;    

    int compteur = 0;

    for (int i = 2; i < n; i++) {
        if (est_premier(i)) {

            for (int tour = 0; tour < nombre_tour; tour++) {
                map_premiers[compteur] = i;
                multimap_premiers.insert({compteur, i});
                set_premiers.insert(i);
                multiset_premiers.insert(i);
            }

            compteur++;
        }
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duree = fin - debut;
    std::cout << "Temps écoulé pour la deuxième équipe : " << duree.count() << " secondes\n";
}



int main() {
    // première équipe 

    generer_premier_equipe_1(1010, 3);

    // deuxième équipe 

    generer_premier_equipe_2(1010, 3);



    // std::cout << est_premier(5) << std::endl; 
    return 0;
}
