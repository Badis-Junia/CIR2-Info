#include <iostream>

class Suite {
protected:
    int terme_initial;
    int raison;
public:
    virtual int calcul_terme_pour_n(int n) = 0;
    virtual int somme_pour_n(int n) = 0;
    friend std::ostream& operator<<(std::ostream & flux, const Suite &masuite);
    friend std::istream& operator>>(std::istream & flux, Suite &masuite);
};

class Suite_arithmetique : public Suite  {
    public:
        Suite_arithmetique();
        Suite_arithmetique(int debut, int maraison);
};


class Suite_geometrique : public Suite  {
    public:
        Suite_geometrique();
        Suite_geometrique(int debut, int maraison);
};

