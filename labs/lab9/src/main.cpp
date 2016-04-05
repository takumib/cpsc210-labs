#include <iostream>

#include "matrix.h"

int main()
{
    // creates a 3x3 matrix
    Matrix a(3, 3);
    Matrix b(3, 3);
    Matrix c(3, 3);
    
    for(int i = 0; i < a.getRows(); i++) {
        for(int j = 0; j < a.getCols(); j++) {
            a[i][j] = 1;
            b[i][j] = 2;
            c[i][j] = i + j;
        }
    }

    Matrix m1(a + b);
    m1.print();

    std::cout << "\n";

    Matrix m2(a - b);
    m2.print();

    std::cout << "\n";

    Matrix m3(a * b);
    m3.print();

    std::cout << "\n";

    Matrix m4(c.transpose());
    m4.print();

    std::cout << "\n";

    return 0;
}
