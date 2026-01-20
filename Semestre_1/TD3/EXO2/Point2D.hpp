#ifndef PAINT3D_HPP
#define PAINT3D_HPP

class Point2D {
private:
    float x, y;

public:
    Point2D();
    Point2D(const float &newx, const float &newy);

    void setXYZ(const float &newx, const float &newy);
    void setX(const float &newx);
    void setY(const float &newy);


    float getX();
    float getY();


    void print();
    float distanceTo(const Point2D &otherPoint2D);
};

#endif


