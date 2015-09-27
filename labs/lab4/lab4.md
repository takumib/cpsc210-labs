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
be working with later on this semester -- we'll use this lab to build up a library of 3d 
vector functions in advance. 

### Representing `vector`s in C with structs

In [vector.c](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab4/src/vector.c) 
we provide you with the skeleton of a vector struct (shown below) that you'll need to
 complete before continuing your library implementation.
```c
typedef struct vector_t {
    //TODO: this needs three components: x, y, and z of type double
} vector;
```

#### More info on structs

You can think of a struct as an *aggregate type*, capable of housing zero or more 
variable declarations. The variable declaration(s) found within a struct are typically 
referred to as *fields*. For a contrived example, the following is a hypothetical struct 
for storing student information:

```c
typedef struct student_info_t {
    int age;
    double gpa;
} sudent_info;
```

The struct declared above contains two fields: `age` and `gpa`. Notice that fields can 
be  declared with different types. To create and start using the above struct, we can 
declare variables of type `student_info` like so:

```c
student_info x;
```

Now that we have a variable `x` of type `student_info`, we can assign values 
(of the appropriate type!) to the fields of `x` in a straightforward way:

```c
x.age = 23;
x.gpa = 2.6;
```

#### References to structs

When dealing with *references* to structs, C employs slightly different notation for 
accessing fields. Consider the following function that takes a pointer to a 
`student_info` struct as a parameter.

```c
void foo(student_info* info) {
    printf("age: %d", info->age, info->gpa);
}
```

Here, because `info` is pointer to a struct, we use C's `->` operator to get at the
fields (as opposed to '`.`' for nonpointer struct-typed variables). It's worth noting 
that the arrow operator used above is merely syntactic sugar* for the more familiar 
(but uglier expression): `(info*).age`. 

|*aside: syntactic sugar|
|-------------|
|*The term ``syntactic sugar" simply means defining some syntactic shortcuts in the language that make it easier for programmars to type and/or read certain constructs*|

### Vector functions

The following listing contains prototypes for some the functions you'll need to implement 
as part of the lab (the complete list can be found in `vectors.c`).

```c
/** Returns the length (magnitude) of v: square x, y, z; sum
 *  the results, then return the square root of the sum.
 */
double vec_len(vector v);

/** Returns a new vector whose components are normalized against v's.
 *  Take each x, y, z of v and divide by the length of v for each.
 */
vector vec_normalize(vector v);

/** Returns a new vector whose components are multiplied by some 
 *  constant, scale: scale * x, scale * y, scale * z.
 */
vector vec_scale(vector v, double scale);
    
/** Returns the dot product of two vectors v1 dot v2: (x1 * x2) + 
 *  (y1 * y2) + (z1 * z2).
 */
double vec_dot(vector v1, vector v2);
```

### Testing

Assuming you are in the directory housing your code, to run all you need to do is type 
`make`. This will compile and generate an executable for your code named `lab4`. To run 
the generated executable, simply type `./lab4`. Additionally, typing `make clean` will 
freshen your current working directory by deleting any gcc-generated `*.o` files.

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

* There are 4 whitespaces separating output of each vector component in the expected output.
* Printing a double with `%.3f` in your format string limits the number of trailing 
places to 3.
* When you first run the test driver, you'll likely see very little output. This is 
probably because you have not yet implemented `vec_print()`. So you might consider 
implementing this function first.
* If after reading this handout in its entirety you're still unsure how to handle the 
`vector` reference parameterizing `vec\_copy()`, refer to this.


## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
tar cvf lab4_handin.tar vector.h vector.c vectortest.c output.txt MakeFile
```
and submit the resulting `lab4_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).