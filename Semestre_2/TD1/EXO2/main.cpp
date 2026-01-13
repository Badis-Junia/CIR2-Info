#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

char succ(char c, const std::vector<char>& alphabet) {
    auto it = std::find(alphabet.begin(), alphabet.end(), c);
    if (it == alphabet.end() || it + 1 == alphabet.end()) {
        return '\0';
    }
    return *(it + 1);
}

void generator(const std::string& test) {
    std::vector<char> lettres(test.begin(), test.end());
    std::sort(lettres.begin(), lettres.end());

    const size_t k = test.size();

    std::string mot(k, lettres.front());
    std::string dernierMot(k, lettres.back());

    
    std::cout << mot << std::endl;

    while (mot != dernierMot) {
        int i = k - 1;

        
        while (i >= 0) {
            char s = succ(mot[i], lettres);
            if (s != '\0') {
                mot[i] = s;
                break;
            } else {
                mot[i] = lettres.front();
                i--;
            }
        }

        std::cout << mot << std::endl;
    }
}

bool verification(const std::string& mot) {
    for (size_t i = 0; i < mot.size(); i++) {
        for (size_t j = i + 1; j < mot.size(); j++) {
            if (mot[i] == mot[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string test;
    std::cout << "Entrez le mot : ";
    std::cin >> test;

    if (verification(test)) {
        generator(test);
    } else {
        std::cerr << "le mot n'est pas valide" << std::endl;
    }

    return 0;
}
