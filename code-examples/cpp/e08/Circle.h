#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double area() {
        return 3.14159 * radius * radius;
    }
};

#endif