#include <iostream>

class Mon_vecteur {
int size_ = 0;
float* tab_;
public:
    Mon_vecteur();
    Mon_vecteur(const int& size);
    int get_size() const;
    float & operator()(const int& ind); //retourne le ième élément de tab_
    float operator*(Mon_vecteur& v); //produit scalaire de 2 vecteurs
    Mon_vecteur &operator*=(const float& val); // produit d'un vecteur par un scalaire
    friend std::ostream& operator<<(std::ostream& os, Mon_vecteur& v);
    ~Mon_vecteur();
};

