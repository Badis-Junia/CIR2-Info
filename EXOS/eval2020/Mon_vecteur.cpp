#include <iostream>
#include "Mon_vecteur.hpp"

Mon_vecteur::Mon_vecteur() : size_(0), tab_(new float[0]) {
}

Mon_vecteur::Mon_vecteur(const int& size) : size_(size), tab_(new float[size]) {
}



int Mon_vecteur::get_size() const {
    return this->size_;
}

float Mon_vecteur::operator*(Mon_vecteur& v) {
    float result;
    for(int i = 0;i<v.size_;i++) {
        result = result + (this->tab_[i] * v.tab_[i]);
    }
    return result;
}

float & Mon_vecteur::operator()(const int& ind) {
    return this->tab_[ind];
}


Mon_vecteur & Mon_vecteur::operator*=(const float& val) {
    for(int i = 0;i<this->size_;i++) {
        this->tab_[i] *= val;

    }
    return *this;
}

Mon_vecteur::~Mon_vecteur() {
    delete[] this->tab_;
}

std::ostream& operator<<(std::ostream& os, Mon_vecteur& v) {
    os << "(";
    for(int i = 0;i<v.size_;i++) {
        os << v.tab_[i] << ",";
    }
    os << ")" << std::endl;
    return os;
}
