#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include "Point2D.hpp"
#include "Point3D.hpp"


class Vecteur {
private:
    float x, y, z; 

public:

    Vecteur(); 
    Vecteur(const Point2D &A, const Point2D &B); 
    Vecteur(const Point3D &A, const Point3D &B, const Point3D &C); 
    Vecteur(float x, float y, float z = 0.0f);


    Vecteur somme(const Vecteur &other) const;
    Vecteur produit(float scalaire) const;
    bool egal(const Vecteur &other) const;


    void print() const;
};

#endif
