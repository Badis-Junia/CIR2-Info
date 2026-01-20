#include <iostream>
#include "Paint3D.hpp"

int main() {
    Point3D p1;           
    Point3D p2(10.0, 20.0, 30.0); 

    p1.print();
    p2.print();

    std::cout << "Distance: " << p1.distanceTo(p2) << std::endl;

    return 0;
}
