#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Point3D.hpp"

Point3D::Point3D() : Point2D() {
    z = static_cast<float>(rand() % 101);
}

Point3D::Point3D(const float &newx, const float &newy, const float &newz)
    : Point2D(newx, newy), z(newz) {}

void Point3D::setXYZ(const float &newx, const float &newy, const float &newz) {
    x = newx; 
    y = newy; 
    z = newz;
}

void Point3D::setZ(const float &newz) { z = newz; }

float Point3D::getZ() const { return z; }

void Point3D::print() {
    std::cout << "Point3D(" << x << ", " << y << ", " << z << ")" << std::endl;
}

float Point3D::distanceTo(const Point3D &otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}
