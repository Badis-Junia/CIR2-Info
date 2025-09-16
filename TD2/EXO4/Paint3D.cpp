#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Paint3D.hpp"

Point3D::Point3D() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    x = static_cast<float>(rand() % 101); 
    y = static_cast<float>(rand() % 101);
    z = static_cast<float>(rand() % 101);
}

Point3D::Point3D(const float &newx, const float &newy, const float &newz)
    : x(newx), y(newy), z(newz) {}

void Point3D::setXYZ(const float &newx, const float &newy, const float &newz) {
    x = newx; y = newy; z = newz;
}

void Point3D::setX(const float &newx) { x = newx; }
void Point3D::setY(const float &newy) { y = newy; }
void Point3D::setZ(const float &newz) { z = newz; }

float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

void Point3D::print() {
    std::cout << "Point3D(" << x << ", " << y << ", " << z << ")" << std::endl;
}

float Point3D::distanceTo(const Point3D &otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}
