## Objectives

As with vectors earlier this semester, in this lab you'll be 
adding some common matrix operations to your expanding library of raytracer utilities. 

The matrix operations we'll be performing here are on fixed, square 3x3 matrices which
should help eliminate some of the edge cases and complexity that arise in needing to deal
with non-square matrices (3x4, 2x1, etc).

As always, if you're hazy on the mathematical notion of a matrix, go ahead and read up 
on them [here]().

## Task: implement 3x3 matrix operations

We'll represent our matrices with 3x3, 2d arrays of type `double`. Here are signatures
for *some* the operations you're expected to implement; the rest are defined in 
`matrix.h`.

```c
/** Given matrices m1 and m2, computes m1 - m2 and puts the resulting matrix
 *  into 'result'.
 */
void matrix_difference(double m1[3][3], double m2[3][3], double result[3][3]);

/** Given matrices m1 and m2, computes m1m2 and puts the resulting matrix into 
 *  result. 
 *  
 *  Note that this is *not* simply multiplying each element in m1 by each in m2! 
 *  It's more like taking the dot product between each row of m1 and column of 
 *  m2. Read up on it here: https://en.wikipedia.org/wiki/Matrix_multiplication
 */
void matrix_multiply(double m1[3][3], double m2[3][3], double result[3][3]);

/** Scales all elements of matrix m1 by 'scale' and places the resulting 
 *  matrix into result.
 */
void matrix_scale(double m1[3][3], double result[3][3], double scale);

/** Computes and replaces m with its transpose. You can read up on transpose 
 *  operation here: https://en.wikipedia.org/wiki/Transpose. Note that this 
 *  operation *replaces* the incoming m.
 */
void matrix_transpose(double m[3][3]);

/** Returns zero iff matrix m is symmetric; any other number otherwise. Note
 *  that this operation should restore m, meaning by the time the function 
 *  ends, m should be the same as its incoming value.
 */
int matrix_is_symmetric(double m[3][3]);
```

## Testing

To compile your code, type `make`. This will build the code gen an executable for it 
automatically. Then to run, all you need to do now is type `./lab7`. Also,
remember that you can freshen your working directory -- deleting any lingering
`*.o` files -- by typing `make clean`.

The expected output can be viewed in [`output.txt`]
(https://github.com/Welchd1/cpsc210-labs/blob/lab7-dev/labs/lab7/src/output.txt).

## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:

```
tar cvf lab7_handin.tar matrix.h matrix.c matrixtest.c output.txt MakeFile
```

and submit the resulting `lab7_handin.tar.gz` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).

## Downloading

As usual you can either browse the default files here on [GitHub]
(https://github.com/Welchd1/cpsc210-labs/tree/lab7-dev/labs/lab7/src) or download the 
starter kit [here]().
