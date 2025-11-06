#include <iostream>

class Fraction {
    private:
        mutable int num;
        mutable int den;
    public:  


        int getnum();
        int getden();
        void setnum(int value);
        void setden(int value);
        friend std::ostream& operator<<(std::ostream& flux, const Fraction & fraction);
        friend std::istream& operator>>(std::istream& flux, const Fraction & fraction);
};
