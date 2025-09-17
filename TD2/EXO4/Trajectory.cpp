#include "Trajectory.hpp"
#include <cmath>
#include <iostream>


Trajectory::Trajectory() {

    for (size_t i = 0; i < numberOfPoints; i++) {

        points[i] = Point3D();
    }
}

void Trajectory::print() {
    std::cout << "Trajectory with " << numberOfPoints << " points:" << std::endl;
    for (size_t i = 0; i < numberOfPoints; i++) {
        std::cout << "Point " << i << ": ";

        std::cout << "(" << points[i].getX() << ", " 
                  << points[i].getY() << ", " 
                  << points[i].getZ() << ")";
        std::cout << std::endl;
    }
}

Point3D& Trajectory::getPoint(const int &n) {
    if (n < 0 || n >= static_cast<int>(numberOfPoints)) {

        std::cerr << "Error: Index " << n << " out of bounds" << std::endl;
        return points[0];
    }
    return points[n];
}

float Trajectory::getTotalDistance() {
    if (numberOfPoints < 2) {
        return 0.0f;
    }
    
    float totalDistance = 0.0f;
    for (size_t i = 1; i < numberOfPoints; i++) {

        float dx = points[i].getX() - points[i-1].getX();
        float dy = points[i].getY() - points[i-1].getY();
        float dz = points[i].getZ() - points[i-1].getZ();
        totalDistance += std::sqrt(dx*dx + dy*dy + dz*dz);
    }
    return totalDistance;
}
