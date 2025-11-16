#include <iostream>

class Polygone{
    protected:
        int cote;
    public: 
        int getcote();
        void setcote(int value);
        friend std::ostream& operator<<(std::ostream& flux, const Polygone & monpoly);

};

class Carre : public Polygone {
    public: 
        int getperimetre();
};
