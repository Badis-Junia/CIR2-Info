#include <iostream>
#include "Vecteur.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"

Vecteur::Vecteur() {
    x = 0;
    y = 0;
    z = 0;
}

Vecteur::Vecteur(const Point2D &A, const Point2D &B) {
    x = A.getX(); y = A.getY();
}

Vecteur::Vecteur(const Point3D &A, const Point3D &B, const Point3D &C) {
    x = A.getX(); y = B.getY(); z = C.getZ(); 
}

Vecteur::Vecteur(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
Vecteur Vecteur::somme(const Vecteur &other) const {
    return Vecteur(x + other.x, y + other.y, z + other.z);
}

Vecteur Vecteur::produit(float scalaire) const {
    return Vecteur(x * scalaire, y * scalaire, z * scalaire);
}
bool Vecteur::egal(const Vecteur &other) const {
    if(Vecteur().x == other.x && Vecteur().y == other.y && Vecteur().z == other.z) {
        return true;
    }
    return false;
}
void Vecteur::print() const {
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;

}


