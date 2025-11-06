#include <string>
#include <iostream>

class Chiffrement {
public:
    std::string texte_;
    virtual std::string chiffrement(const std::string &texte_a_chiffrer) = 0;
    virtual std::string dechiffrement(const std::string &texte_a_chiffrer) = 0;
    friend std::istream& operator>>(std::istream& flux, const Chiffrement & chiffrement);
    friend std::ostream& operator<<(std::ostream& flux, const Chiffrement & chiffrement);

};

class Chiffrement_Cesar : public Chiffrement {
private:
    const int nb_decal_;
public:
    Chiffrement_Cesar();
    Chiffrement_Cesar(const int &nb_decal);
    std::string chiffrement(const std::string &texte_a_chiffrer) const;
    std::string dechiffrement(const std::string &texte_a_dechiffrer) const;

};

class Chiffrement_Vigenere : public Chiffrement {
private:
    const std::string password_;
public:
    Chiffrement_Vigenere();
    Chiffrement_Vigenere(const std::string & password);
    std::string chiffrement(const std::string &texte_a_chiffrer) const;
    std::string dechiffrement(const std::string &texte_a_dechiffrer) const;

};


