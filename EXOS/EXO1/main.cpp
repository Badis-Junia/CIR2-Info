#include <iostream>

int main() {
    float nombre;
    std::cout << "Choisissez le nombre que vous voulez mettre : ";
    std::cin >> nombre;
    for(float i  =0.0f;i<10;i++) {
        std::cout << i << "x" << nombre << "=" << nombre * i << " ";
    }
    return 0;
}
