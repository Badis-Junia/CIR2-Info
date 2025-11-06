#include <iostream>
#include "Chiffrement.hpp"

Chiffrement_Vigenere::Chiffrement_Vigenere() {
    this->texte_ = "";
}
std::istream& operator>>(std::istream& flux, const Chiffrement& chiffrement) {

}

std::ostream& operator<<(std::ostream& flux, const Chiffrement& chiffrement) {
    Chiffrement_Vigenere test;
    flux << chiffrement.texte_
    return flux;
}
