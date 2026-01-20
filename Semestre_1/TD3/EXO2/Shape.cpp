#define _USE_MATH_DEFINES 
#include <math.h>
#include "Shape.hpp"

unsigned Shape::global_count_ = 0;

Shape::Shape(const Color &color) : color_(color)
{
    count_ = global_count_++;
}

Rectangle::Rectangle(const float &length, const float &width)
{

    this->length_ = length;
    width_ = width;
}

float Rectangle::get_aera()
{
    return length_ * width_;
}

void Rectangle::print_data()
{
    cout << "Shape type : Rectangle with sides : " << length_ << " " << width_ << endl;
}

Triangle::Triangle(const float &length_side1, const float &length_side2, const float &length_side3) : length_side1_(length_side1), length_side2_(length_side2), length_side3_(length_side3)
{
}

float Triangle::get_aera()
{
    float s = (length_side1_ + length_side2_ + length_side3_) / 2;
    return sqrt(s * (s - length_side1_) * (s - length_side2_) * (s - length_side3_));
}

void Triangle::print_data()
{
    cout << "Shape type : Triangle with sides : " << length_side1_ << " " << length_side2_ << " " << length_side3_ << endl;
}

Circle::Circle(const float &radius) : radius_(radius) {
}
float Circle::get_aera() {
    return (float)M_PI * radius_ * radius_;
}

void Square::print_data() {
    cout << "Shape type : Circle with radius : " << length_ << endl;
}
void Square::print_area() {
    cout << "Shape type : Circle with radius : " << pow(length_, 2) << endl;
}

