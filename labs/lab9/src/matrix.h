#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <ostream>

class Matrix {
public:
    Matrix(int, int); 
    Matrix(const Matrix&);
    ~Matrix();

    Matrix& operator=(const Matrix&);

    // Matrix Matrix operations
    Matrix operator+(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator-(const Matrix&);

    void print();

    double* operator[](int);
    const double* operator[](int) const;

    int getRows() const;
    int getCols() const;

    Matrix transpose() const;

private:
    int rows;
    int cols;
    double** mat;
};

#endif // MATRIX_H
