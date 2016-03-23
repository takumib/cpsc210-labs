#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    Shape();
    Shape(double, double);
    double getWidth();
    double getHeight();
    virtual double computeArea() = 0;

    void setWidth(double);
    void setHeight(double);

protected:
    double width;
    double height;
};

#endif
