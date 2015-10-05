## Objectives

As with vectors earlier this semester, in this lab you'll be 
adding some common matrix operations to your expanding library of raytracer utilities. 

The matrix operations we'll be performing here are on fixed, square 3x3 matrices which
should help eliminate some of the edge cases and complexity that arise in needing to deal
with non-square matrices (3x4, 2x1, etc).

As always, if you're hazy on the mathematical notion of a matrix, go ahead and read up 
on them [here](https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/matrices.pdf).

**Note:** Please read through all instructions carefully. You are responsible for handing 
in all material on time and correctly as well as following grading criteria below.

Finally, after reading **all** sections, download the lab with the link at the bottom.

## Task: implement 3x3 matrix operations

We'll represent our matrices with 3x3, 2d arrays of type `double`. Here are signatures
for *some* of the operations you're expected to implement; the rest are defined in 
`matrix.h`.

```c
/*  
 * Given matrices m1 and m2, compute m1 - m2 and put the resulting matrix
 * into 'result'.
 */
void matrix_difference(double m1[3][3], double m2[3][3], double result[3][3]);

/*
 * Given matrices m1 and m2, compute m1m2 and put the resulting matrix into 
 * result. 
 *  
 * Note that this is *not* simply multiplying each element in m1 by each in m2! 
 * It's more like taking the dot product between each row of m1 and column of 
 * m2. Read up on it [here](https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/matrices.pdf).
 */
void matrix_multiply(double m1[3][3], double m2[3][3], double result[3][3]);

/* 
 * Modifies matrix m by multiplying all of its elements by 'scale' 
 */
void matrix_scale(double m[3][3], double scale);

/*
 * Computes and replaces m with its transpose. You can read up on transpose 
 * operation [here](https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/matrices.pdf).
 * Note that this operation *replaces* the incoming m.
 */
void matrix_transpose(double m[3][3]);

/*
 * Returns zero if matrix m is symmetric; any other number otherwise. Note
 * that this operation should restore m, meaning by the time the function 
 * ends, m should be the same as its incoming value.
 */
int matrix_is_symmetric(double m[3][3]);
```

## 2D Array Notation

In this lab, we will use 2D array notation. We have seen 1D array notation before.

```c
// 1D array example
double a[5] = {0, 1, 2, 3, 4};
```

In order to represent a matrix more naturally, we will construct 2D arrays. To construct a 2D array we add another bracket to denote the additional dimension.

```c
// 2D array example
double m[3][3] = {
                  { 0, 1, 2 },
                  { 4, 5, 6 },
                  { 7, 8, 9 }
                 };
```

Take note of the above creation of a 2D `double` array. We can imagine the 2D array as an array of 1D arrays. To access a particular element from `m` after we have created it, we must use valid indices for accessing `m `. We denote the particular row and column that we wish to receive by writing `m[i][j]` where `i` denotes the row and `j` denotes the column starting at index 0. So, `m[0][0]` accesses the top left element and `m[2][2]` accesses the bottom right element. We can also set an element in `m` by using the assignment operator `=` like this `m[1][1] = 0`. This sets the middle element in the matrix to 0. In order to access or set each element in a matrix we will use doubly and triply nested for-loops as discussed in the next section. For specific matrix operation help, please use [A Brief Introduction to Matrix Operations](https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/matrices.pdf).

## Using a doubly or triply nested for-loop

So far in our labs, we have dealt with a single nested for-loop. This is ideal for situations where we are dealing with 1D arrays. If we need to perform operations on 2D arrays, like matrices, we can nest for-loops to access every element in the array.

```c
for(int i = 0; i < 3; i++) {
  for(int j = 0; j < 3; j++) {
    // result[i][j] = ...;
  }
}
```
In the code above, we create a doubly nested for-loop. When accessing a 2D array using this method, we use the outer loop to denote the row we want to access. The inner loop we use to access the column of interest. Thus, we use the notation `result[i][j]` to set the ith row and jth column of a matrix result. 

**Note:** when dealing with matrices, we read them from left to right, and top to bottom starting at index 0. The top-left is row 0, column 0, and bottom right is row 2, column 2.

We may need to go a step further and use a triply nested for-loop like in `matrix_multiply()` to access a row from `m1` and a column from `m2`. Do do this we write the loop as follows:

```c
double sum = 0.0;
for(int i = 0; i < 3; i++) {
  for(int j = 0; j < 3; j++) {
    sum = 0.0;
    for(int k = 0; k < 3; k++) {
      // sum += ...;
    }
  }
}
```
Remember that when going through the for-loop, the innermost loop will complete first (k loop), then the next loop (j loop), and finally the outermost loop. We continue going through the loop until the outermost loop runs 3 times.

**Note:** use the fact that we want to use the corresponding row of `m1` and column of `m2` as a hint to construct your assignment.

## Testing

To compile your code, type `make`. This will build the code and generate an executable for it 
automatically. Then to run, all you need to do now is type `./lab7`. Also,
remember that you can freshen your working directory -- deleting any lingering
`*.o` files -- by typing `make clean`.

The expected output can be viewed in [`output.txt`]
(https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/src/output.txt).

## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:

```
tar cvf lab7_handin.tar matrix.h matrix.c matrixtest.c output.txt Makefile
```

and submit the resulting `lab7_handin.tar.gz` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).

## Due Date

As always labs are due the day after your assigned lab section by 11:59pm.

## Grading

You will be grading using the following criteria:

* Correctness of output for each function.
* Use of double/triple nested for-loops for solutions. (Note: only matrix_multiply uses a triple for-loop)
* Proper use of comments. (Note: you do not need to over comment; we are just looking for a brief explanation of your code)
  * Comments are also very helpful if your function does not work because we offer partial credit if your logic is correct.
* Proper use of spaces/indentation. (Note: look at the indentation noted below; do not left-align all of you code)
  * You do not need to follow this exact level of indentation, this is just a template.
  * Just make sure that your indentation is consistent.
* Logical use of variable names
  * ex: don't name variables x, something, not_sure, etc.
  * It's ok to use i, j, and k as variables in for loops.
  * Use some naming scheme that provides context to your variable
* Handing in correct materials
  * matrix.c, matrix.h, matrixtest.c, Makefile, and output.txt inside lab7_handin.tar.gz (Note: use command from above)
* On-time submission

As always, partial submission are always accepted and will give you at least a 50%. Generally, the grade will be much higher unless the program contains too many errors.

## Indentation Example

```c
#include <stdio.h>

int main() {
  double m[3][3] = {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}
                   };
  
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      m[i][j] = 1;
    }
  }

  return 0;
}
```

## Downloading and Decompressing.

As usual you can either browse the default files here on [GitHub]
(https://github.com/Welchd1/cpsc210-labs/tree/lab7-dev/labs/lab7/src) or download the 
starter kit [here](https://github.com/Welchd1/cpsc210-labs/releases/download/7.0/lab7.tar.gz).

After you have downloaded `lab7.tar.gz` you can decompress this by typing:

`tar xzvf lab7.tar.gz`

**Note:** remember to move your `lab7.tar.gz` into your cpsc2101/lab7 directory before decompression.

## Final Note

At any point during or after the lab, do not hesitate to ask for help or send an email to both **Takumi Bolte** (tbolte@g.clemson.edu) and **Daniel Welch** (dtwelch@g.clemson.edu). We will try to respond as fast as we can through email and can set up one-on-one meeting times depending on our schedule for the week.
