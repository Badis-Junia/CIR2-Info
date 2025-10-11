#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    int a;
    std::vector<int> tab;
    for(int i = 0;i<5;i++) {
        std::cin >> a;
        tab.push_back(a);
    }
    for(long unsigned int i = 0;i<tab.size();i++) {
        std::cout << tab[i] <<std::endl;
    }
    std::cout << "t est"<<std::endl;
    std::cout << std::endl;

    std::sort(tab.begin(), tab.end());
    for(long unsigned int i = 0;i<tab.size();i++) {
        std::cout << tab[i] <<std::endl;
    }
    return 0;
}
