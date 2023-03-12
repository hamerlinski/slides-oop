#include <iostream>

#include "Rectangle.h"
#include "Circle.h"

void printArea(Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rectangle(5, 10);
    Circle circle(5);
    printArea(rectangle);
    printArea(circle);
    return 0;
}