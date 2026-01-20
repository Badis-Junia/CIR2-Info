#ifndef TRAJECTORY_HPP
#define TRAJECTORY_HPP

#include "Paint3D.hpp"
#include <cstddef>

constexpr size_t numberOfPoints = 10;

class Trajectory {
private:
    Point3D points[numberOfPoints];

public:
    Trajectory();
    void print();
    Point3D& getPoint(const int &n);
    float getTotalDistance();
};

#endif
