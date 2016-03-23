#include <iostream>

#include "circle.h"
#include "rectangle.h"

int main()
{
    // creating a rectangle with width and height 3.0 and 4.0
    Rectangle r(3.0, 4.0);

    std::cout << "Rectangle's area: " << r.computeArea() << std::endl;


    Circle c(3.0);
    std::cout << "Circle's area: " << c.computeArea() << std::endl;
    std::cout << "Circle's circumference: " << c.computeCircumference()
              << std::endl;

    // TODO: test your right triangle code here.
    
    return 0;
}
