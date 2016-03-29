#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    Shape();
    Shape(double, double);
    double getWidth();
    double getHeight();
    virtual std::string getDescription() = 0;
    virtual double computeArea() = 0;

    void setWidth(double);
    void setHeight(double);

protected:
    double width;
    double height;
};

#endif
