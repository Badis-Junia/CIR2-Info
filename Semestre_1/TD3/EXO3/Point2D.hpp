#ifndef POINT2D_HPP
#define POINT2D_HPP

class Point2D {
protected:
    float x, y;

public:
    Point2D();
    Point2D(const float &newx, const float &newy);

    void setXY(const float &newx, const float &newy);
    void setX(const float &newx);
    void setY(const float &newy);

    float getX() const;
    float getY() const;

    void print();
    float distanceTo(const Point2D &otherPoint2D);
};

#endif
