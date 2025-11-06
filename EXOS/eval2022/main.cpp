#include <iostream>
#include "Suite.hpp"

int main() {

    const unsigned size = 2;
    const unsigned n = 5;
    auto *sa = new Suite_arithmetique(0, 2);
    auto *sg = new Suite_geometrique(1, 2);
    Suite *tab[size] = {sa, sg};
    for (unsigned i = 0; i < size; ++i) {
        std::cout << *(tab[i]) << std::endl;
        std::cout << std::endl;
    for (unsigned j = 0; j <= n; ++j) {
        std::cout << "calcul_terme_pour_n : " << j << " = " << tab[i]→calcul_term;
    }
    std::cout<<std::endl;
    std::cout << "calcul_somme_pour_n : " << n << " = " << tab[i]→calcul_som;
    std::cout << std::endl;
}
return EXIT_SUCCESS;
}
