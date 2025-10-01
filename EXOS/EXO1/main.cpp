#include <iostream>

int main() {
    int nombre;
    std::cout << "Choisissez le nombre que vous voulez mettre : ";
    std::cin >> nombre;
    for(int i  =0;i<10;i++) {
        std::cout << i << "x" << nombre << "=" << nombre * i << " ";
    }
    return 0;

}
