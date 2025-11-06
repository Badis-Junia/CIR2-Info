class Polygone{
    protected:
        int cote;
    public: 
        int getcote();
        void setcote(int value);

};

class Carre : public Polygone {
    public: 
        int getperimetre();
};
