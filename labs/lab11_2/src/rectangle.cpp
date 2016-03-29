#include "rectangle.h"

Rectangle::Rectangle() :
    Shape()
{}

Rectangle::Rectangle(double w, double h) :
    Shape(w, h)
{}

double Rectangle::computeArea()
{
    return width * height;
}
