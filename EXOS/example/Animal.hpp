#include <iostream>
#include <string>
class Animal {
    private:
        std::string espece;
    public:
        std::string getespece();
        void setespece(std::string unespece);
        friend std::ostream& operator<<(std::ostream & flux, const Animal & animal);
        friend std::istream& operator>>(std::istream & flux, Animal & animal);
};
