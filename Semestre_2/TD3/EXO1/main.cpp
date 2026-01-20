#include <bits/stdc++.h>
#include <string>

void toutesLesPermutations(std::string & villes, int debut, int fin) {
    if (debut == fin)
        std::cout << villes << std::endl;
    else {
        for (int i = debut; i <= fin; i++) {
            std::swap(villes[debut], villes[i]);
            toutesLesPermutations(villes, debut+1, fin);
            std::swap(villes[debut], villes[i]);
        }
    }
}

int main() {
    std::string villes = "AB";
    toutesLesPermutations(villes, 0, villes.size() - 1);
    return 0;
}

// -------------------------------------- La Trace -----------------------------------------------
// void toutesLesPermutations(std::string &villes, int debut, int fin, int &compteur) { AB, 0, 1, 1
//     if (debut == fin) { 0 == 1 
//         std::cout << compteur << " : " << villes << std::endl; on passe ça 
//         compteur++; on passe ça 
//     } else {
//         for (int i = debut; i <= fin; i++) { i = 0, i <= 1
//             std::swap(villes[debut], villes[i]); on se retrouve avec B,A
//             toutesLesPermutations(villes, debut + 1, fin, compteur); // BA, 1, 1, 2
//             std::swap(villes[debut], villes[i]); // on a AB
//         }
//     }
// }



