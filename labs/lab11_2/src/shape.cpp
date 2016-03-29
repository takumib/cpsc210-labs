#include "shape.h"

Shape::Shape() :
    width(0),
    height(0)
{}

Shape::Shape(double w, double h) :
    width(w),
    height(h)
{}

double Shape::getWidth()
{
    return width;
}

double Shape::getHeight()
{
    return height;
}

void Shape::setWidth(double w)
{
    width = w;
}

void Shape::setHeight(double h)
{
    height = h;
}
