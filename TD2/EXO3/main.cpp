#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cctype>

int main() {
    std::string nomdufichier;
    std::cout << "Quel est le nom du fichier dans le répertoire ?  : ";
    std::cin >> nomdufichier;
    std::ifstream fichier(nomdufichier);

    if(!fichier) {
        std::cerr << "Nous n'avons pas trouvé le fichier " <<std::endl;
        return 1;
    }
    
    int lignes = 0;
    int mots = 0;
    int lettres = 0;
    std::string ligne;
    
    std::vector<int> occurrences(26, 0);
    
    while(std::getline(fichier, ligne)) {
        lignes++;
        std::stringstream ss(ligne);
        std::string mot;

        while(ss >> mot) {
            mots++;
            for(int i = 0; i < mot.size(); i++) {
                char c = mot[i];

                if (std::isalpha(c)) {
                    lettres++;

                    char lettre_min = std::tolower(c);
                    occurrences[lettre_min - 'a']++;
                }
            }
        }
    }
    fichier.close();

    std::cout << "Voilà l'analyse du fichier : " << std::endl;
    std::cout << "Nombre de mots " << std::setw(5) << ": " <<  mots << std::endl;
    std::cout << "Nombre de lignes " << std::setw(3) << ": " << lignes << std::endl;
    std::cout << "Nombre de lettres " << std::setw(1) << ": " << lettres << std::endl;
    

    std::cout << "\nOccurrences de chaque lettre :" << std::endl;
    for (int i = 0; i < 26; i++) {
        char lettre = 'a' + i;
        std::cout << lettre << " : " << occurrences[i] << std::endl;
    }

    int max = 0;
    int index = 0;
    for(int i = 0;i<occurrences.size();i++) {
        if(occurrences[i] > max) {
            max = occurrences[i];
            index = i; 
        }
    }
    std::cout << "La lettre la plus présente est la lettre " << char('a' + index) << std::endl;

    return 0;
}
