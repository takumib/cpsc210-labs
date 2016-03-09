## Objectives

In today's lab, we will be implementing parts of a `Matrix` class in c++ using several new techiques: references and operator overloading. We have previously seen and implemented our own matrix in C using arrays. We can make use of the many new features that C++ uses to implement a matrix. Additionally we will learn how to use operator overloading to more naturally define a matrix as well as using references. 

## Task 1: understand and implement the `Matrix` class

```c++
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
```

In the above implementation of a matrix, we have added several special methods that are prefixed with the word `operator` followed by an operation can be performed my a matrix and another type. 

## Operator Overloading

Operator overloading enables custom operations to be defined for a given object. For example, in the C version of our matrix lab, we had to define the matrix add operation by creating a function called matrix_add(double m1[][], m2[][]) which took two double arrays. 

In our C++ version, a slight improvement to this would be able to add two matrices together just as we would with integers, floats, or doubles:

Matrix a;
Matrix b;
Matrix c = a + b;

Operator overloading in fact gives us the power to do this as well as providing us with many more operations to perform as you will implement in today's lab.

|*a note on operators|
|-------------|
|*In case you're unaware, symbols such as '+', '-', '\', etc are commonly referred to as binary (infix) operators. Infix means the name sits in the middle of two (left and right hand side) arguments.*|

```c++
Matrix operator+(const Matrix&);
```
The syntax for this can admittedly be kind of confusing if you're seeing it for the first time, so we'll walk through it here. As we're used to, the return type, `Matrix`, is the first thing we declare, so think of this as the type that results from applying the `+` operator. Next, we write `operator` followed immediately by the symbol we want to overload, in this case: `+` (note that C++ internally has a fixed list of acceptable operator symbols, so you can't just use anything as an operator, like `j` -- C++ must approve of it).

You'll note also that we've declared only a single parameter, `const Matrix&`, which can be kind of confusing since we already stated that `+` should have two parameters -- one corresponding to the left-hand-side of the operator, and one for the right-hand-side. In this case however, the `Matrix` object itself serves as an *implicit* left hand side argument, this is why we declare only one formal parameter to the function.

## Using the `new` operator with arrays

When we want to create a pointer array using the using malloc we would normally type something like:

```c
int* x = (int*)malloc(sizeof(int) * 10);
```

Now, with C++ we can replace this with the new operator:

```c++
int* x = new int[10];
```

Note the syntax if we want to create an array of 10 elements for the integer array.

If we wanted to create a 2-D array in C++, we can extend this further by first allocating the number of rows that we want and the number of columns that we want.

```c++
int** x = new int*[rows];
for(int i = 0; i < rows; i++) {
    x[i] = new int[cols];
}
```
This will be the type of initialization we want for our `Matrix` constructor.

## Deleting our `Matrix`

Since we used the `new` operator to create our matrix, we will need to use the `delete` operator to delete our matrix. Similar to our constructor we first begin by deleting each of the columns row by row.

for(int i = 0; i < rows; i++) {
    delete[] x[i];
}

delete[] x;

Note the syntax of `delete`. Since we are deleting an array of items we use `delete[]` rather than just `delete`. This code will be used in the destructor.

## Testing

To compile and test your code type this:

```c++
g++ main.cpp matrix.cpp -o lab9
```

## Handin

To hand in your project use the *tar cvf* command to turn in all of your `.cpp` and `.h` files and name the file `lab9_handin.tar`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 9.

## Starter kit
Dowload using [this](https://github.com/takumib/cpsc210-labs/releases/download/9.0/lab9.tar) link.
