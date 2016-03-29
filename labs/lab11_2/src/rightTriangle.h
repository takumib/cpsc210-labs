#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "shape.h"

class RightTriangle : public Shape {
public:
    RightTriangle();
    RightTriangle(double, double);
    double computeArea();
};

#endif
