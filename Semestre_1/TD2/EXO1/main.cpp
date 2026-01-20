#include <iostream>

constexpr int multiplier(const int &a,const int &b) {
    return a*b;
}

// consteval int multiplierdeux(const int &a,const int &b) { 
//     return a*b; ne marche que pour au dessus de C++ 20, décommentez pour exécuter si c'est le cas 
// }


using namespace std;

int main() {
    int a;
    int b;
    cout << "Entrez une valeur :" << endl;
    cin >> a;
    cout << "Entrez une autre valeur :" << endl;
    cin >> b;
    cout << multiplier(a+1, b+1) << endl;
    // cout << multiplierdeux(a+1, b+1) << endl; même chose ici 
    return 0;
}
