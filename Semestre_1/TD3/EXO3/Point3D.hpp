#ifndef POINT3D_HPP
#define POINT3D_HPP

#include "Point2D.hpp"

class Point3D : public Point2D {
private:
    float z;

public:
    Point3D();
    Point3D(const float &newx, const float &newy, const float &newz);

    void setXYZ(const float &newx, const float &newy, const float &newz);
    void setZ(const float &newz);

    float getZ() const;

    void print();
    float distanceTo(const Point3D &otherPoint3D);
};

#endif
