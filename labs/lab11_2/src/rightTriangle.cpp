#include "rightTriangle.h"

RightTriangle::RightTriangle() :
    Shape()
{}

RightTriangle::RightTriangle(double b, double h) :
    Shape(b, h)
{}

double RightTriangle::computeArea()
{
    return (width * height) / 2.0;
}
