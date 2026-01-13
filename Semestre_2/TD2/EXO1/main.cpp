#include <iostream>

#include <stack>
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

// façon à respecter exactement ce que demande la consigne en utilisant l'example avec le vector, pas opti 
void generer_premier_equipe_1(int n, int nombre_tour) {
    int i = 2;
    auto debut = std::chrono::high_resolution_clock::now();
    std::stack<int> stack_nombre_entiers_premiers;
    std::vector<int> vector_nombre_entiers_premiers;
    std::list<int> liste_nombre_entiers_premiers;
    std::queue<int> queue_nombre_entiers_premiers;
    int compteur_pour_tableau = 0;
    if(n <= 1000) {
        std::cout << "Prenez un entier supérieur à 1000" << std::endl;
    }
    while(i < n) {
        if(est_premier(i)) {
            vector_nombre_entiers_premiers.push_back(i);
        }
        compteur_pour_tableau++;
        i++;
    }
    for(int i =0;i<nombre_tour;i++) {
        while (vector_nombre_entiers_premiers.size()) {
            liste_nombre_entiers_premiers.push_back(vector_nombre_entiers_premiers.back());
            vector_nombre_entiers_premiers.pop_back();
        }
        while (liste_nombre_entiers_premiers.size()) {
            stack_nombre_entiers_premiers.push(liste_nombre_entiers_premiers.back());
            liste_nombre_entiers_premiers.pop_back();
        }
        while (stack_nombre_entiers_premiers.size()) {
            queue_nombre_entiers_premiers.push(stack_nombre_entiers_premiers.top());
            stack_nombre_entiers_premiers.pop();
        }
        while (queue_nombre_entiers_premiers.size()) {
            vector_nombre_entiers_premiers.push_back(queue_nombre_entiers_premiers.back());
            queue_nombre_entiers_premiers.pop();
        }
    }
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duree = fin - debut;
    std::cout << "Temps écoulé pour la première équipe : " << duree.count() << " secondes\n";
}


// respecte aussi la consigne mais de manière optimisé, on voulait montrer qu'on peut utiliser deux méthodes différentes qui marchent
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

    generer_premier_equipe_1(1010, 50);

    // deuxième équipe 

    generer_premier_equipe_2(1010, 50);



    // std::cout << est_premier(5) << std::endl; 
    return 0;
}
