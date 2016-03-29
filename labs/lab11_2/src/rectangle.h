#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(double, double);
    double computeArea();
};

#endif
