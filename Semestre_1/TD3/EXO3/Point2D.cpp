#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Point2D.hpp"

Point2D::Point2D() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    x = static_cast<float>(rand() % 101); 
    y = static_cast<float>(rand() % 101);

}

Point2D::Point2D(const float &newx, const float &newy)
    : x(newx), y(newy) {}

void Point2D::setXY(const float &newx, const float &newy) {
    x = newx; y = newy; 
}

void Point2D::setX(const float &newx) { x = newx; }
void Point2D::setY(const float &newy) { y = newy; }


float Point2D::getX() const { return x; }
float Point2D::getY() const { return y; }


void Point2D::print() {
    std::cout << "Point2D(" << x << ", " << y << ")" << std::endl;
}

float Point2D::distanceTo(const Point2D &otherPoint2D) {
    float dx = x - otherPoint2D.x;
    float dy = y - otherPoint2D.y;
    return std::sqrt(dx*dx + dy*dy);
}


