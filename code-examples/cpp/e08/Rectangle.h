#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() {
        return width * height;
    }
};

#endif