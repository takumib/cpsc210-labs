## Objectives

In this lab your going to be implementing several functions that will allow us to
perform vector arithmetic. If you're somewhat hazy on vectors themselves, go ahead and
read up on them [here]
(http://www.mathhands.com/104/hw/104c06s08ns.pdf).

Finally, you can download your starter kit on the 
[releases page](https://github.com/Welchd1/cpsc210-labs/releases), or peruse the default 
[lab sources](https://github.com/Welchd1/cpsc210-labs/tree/master/labs/lab4/src) here on 
Github.

## Task: implement a 3d vector function library

Since vectors are commonplace in most raytracers -- such as the one you'll 
be working with later on this semester -- you will build up a utility library of 3d 
vector functions in advance. 

### Representing vectors with `vector_t`

In [vector.h]() we provide you with the skeleton of a vector 
struct (shown below) that you'll need to complete before continuing your library 
implementation.
```c
typedef struct vector {
    //TODO: this needs three components: x, y, and z of type double
} vector_t;
```

### Vector functions
The following is a listing of prototypes for the functions you'll need to implement. Each
is preceded by an *informal specification* reviewing some of the steps/computations 
involved.

```c
/** Returns the length (magnitude) of v: square x, y, z; sum
 *  the results, then return the square root.
 */
double vec_len(vector_t v);

/** Returns a new vector whose components are normalized against v's.
 *  Take each x, y, z of v and divide by the length of v for each.
 */
vector_t vec_normalize(vector_t v);

/** Returns a new vector whose components are multiplied by some 
 *  constant, scale: scale * x, scale * y, scale * z.
 */
vector_t vec_scale(vector_t v, double scale);

/** Returns the dot product of two vectors v1 dot v2: (x1 * x2) + 
 *  (y1 * y2) + (z1 * z2).
 */
double vec_dot(vector_t v1, vector_t v2);

/** Returns a new vector that is the sum of v1 + v2: x1 + x2, 
 *  y1 + y2, z1 + z2.
 */
vector_t vec_add(vector_t v1, vector_t v2);

/** Returns a new vector that is the difference of v1 - v2:
 *  x1 - x2, y1 - y2, z1 - z2.
 */
vector_t vec_subtract(vector_t v1, vector_t v2);

/** Copies the components of vector v into result_v. Note: realize that 
 *  result_v is a pointer to a vector_t. Use C's to '->' operator to 
 *  access the fields of result_v.
 */
void vec_copy(vector_t *result_v, vector_t v);

/** Prints a string representation of vector v to stdout */
void vec_print(char *label, vector_t v);
```

### Testing

Assuming you are in the directory housing your code, to run all you need to do is type 
`make` followed by `./lab4` to execute the `vectortest` driver. Also, typing `make clean` 
will freshen your current working directory by deleting any gcc-generated `*.o` 
files, etc.

Here is the expected output: 

```
v1:    2.000    4.000    7.000
v2:    1.000   -3.000    2.000
v1 - v2 = :    1.000    7.000    5.000
Copy of v2:    1.000   -3.000    2.000
v1 dot v2 is    4.000 
Length of v1 is    8.307 
v1 scaled by its 6:   12.000   24.000   42.000
v1 normalized:    0.241    0.482    0.843
v1 + v2 = :    3.000    1.000    9.000
```
*(Beyond achieving the correct answers, it would be hugely helpful to the TAs if you
try to match the expected output as closely as possible in terms of spacing, formatting,
etc; though it's not a hard requirement)*
## Hints

* There are 4 whitespaces separating output of each vector's component in the expected output.
* Printing a double with `%.3f` in your format string limits the number of trailing 
places to 3.
* When you first run the test driver, you'll likely see very little output. This is 
probably because you have not yet implemented `vec_print()`. So you might consider 
implementing this function first.
* If you're unsure how to handle the vector reference parameterizing `vec_copy()`, refer 
to [this](http://www.cs.usfca.edu/~wolber/SoftwareDev/C/CStructs.htm).

## Submission

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
tar cvf lab4_handin.tar vector.h vector.c vectortest.c output.txt MakeFile
```
and submit the resulting `lab4_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).