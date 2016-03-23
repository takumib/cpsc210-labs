#include "circle.h"

#include <cmath>

Circle::Circle() :
    Shape()
{}

Circle::Circle(double radius) :
    Shape(radius, radius)
{}

double Circle::computeArea() 
{
    return M_PI * pow(width, 2);
}

double Circle::computeCircumference()
{
    return 2 * M_PI * width;
}
