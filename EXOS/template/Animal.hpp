#include <iostream>

template<typename T>
class Oiseau {
    private:
        T test;        
    public:
        void setoiseau(T oiseau) { this->test = oiseau; }
        T getoiseau() const { return this->test; }
        friend std::ostream& operator<<(std::ostream& flux, const Oiseau<T> & oiseau) {
            flux << oiseau.getoiseau() << std::endl;
            return flux;
        }
};
