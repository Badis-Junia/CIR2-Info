#include <iostream>
#include <vector>

class Big_natural_number {
private:
    std::vector<unsigned short> tab_;
public:
    Big_natural_number operator+(const Big_natural_number &other) const;
    Big_natural_number operator*(const short unsigned &nb) const;
    Big_natural_number operator*(const Big_natural_number &other) const;
    friend Big_natural_number &operator>>(Big_natural_number &other, const int &nb);
    friend std::ostream &operator<<(std::ostream &os, const Big_natural_number &other);
};


