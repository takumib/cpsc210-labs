#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle();
    Circle(double);
    double computeArea();
    double computeCircumference();
};

#endif
