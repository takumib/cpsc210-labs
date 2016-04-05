#include "matrix.h"

#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

/*
 * Parameterized constructor that takes
 * in the rows and columns
 */
Matrix::Matrix(int r, int c) :
{
}

/*
 * Copy constructor.
 * It takes in a matrix and copies
 * in the new values to this matrix.
 *
 * DO NOT TOUCH
 */
Matrix::Matrix(const Matrix& rhs) 
{
    for(int i = 0; i < rows; i++) {
        delete[] mat[i];
    }

    delete[] mat;

    rows = rhs.rows;
    cols = rhs.cols;

    mat = new double*[rows];
    for(int i = 0; i < rows; i++) {
        mat[i] = new double[cols]();
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            mat[i][j] = rhs[i][j];
        }
    }
}

/*
 * Destructor. Deletes the matrix.
 */
Matrix::~Matrix()
{
}

/*
 * Adds two matrices together
 *
 * same as c version
 */
Matrix Matrix::operator+(const Matrix& rhs)
{
}


/*
 * Multiplies two matrices.
 *
 * DO NOT TOUCH
 */
Matrix Matrix::operator*(const Matrix& rhs)
{
    Matrix ret(getRows(), rhs.getCols());
    if(getCols() == rhs.getRows()) {
        for(int i = 0; i < ret.getRows(); i++) {
            for(int j = 0; j < ret.getCols(); j++) {
                for(int k = 0; k < getCols(); k++) {
                    ret[i][j] += (*this)[i][k] * rhs[k][j];
                }
            }
        }
    }

    return ret;
}

/*
 * Subtracts two matrices
 *
 * same as c version
 */
Matrix Matrix::operator-(const Matrix& rhs)
{
}

/*
 * Prints out the matrix
 *
 * DO NOT TOUCH
 */
void Matrix::print()
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    for(int i = 0; i < rows; i++) {
        std::cout << "[";
        for(int j = 0; j < cols; j++) {
            std::cout.width(0);
            j == getCols()-1 ? std::cout << (*this)[i][j] : 
                 std::cout << (*this)[i][j] << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

/*
 * Allows us to acces the matrix using the
 * bracket "[]" operator
 *
 * DO NOT TOUCH
 */
double* Matrix::operator[](int row)
{
    return mat[row];
}

/*
 * Allows us to acces the matrix using the
 * bracket "[]" operator
 *
 * DO NOT TOUCH
 */
const double* Matrix::operator[](int row) const
{
    return mat[row];
}

/*
 * returns the number of rows in the matrix.
 *
 * Hint: we stored this in a member variable.
 */
int Matrix::getRows() const
{
}

/*
 * returns the number of columns in the matrix.
 *
 * Hint: we stored this in a member variable.
 */
int Matrix::getCols() const
{
}

/*
 * Matrix transpose
 *
 * same as c version
 */
Matrix Matrix::transpose() const
{
}
