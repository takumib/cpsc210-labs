/** vector.c -- cpsc 210 lab 4 
 *  name: 
 *  lab-section:
 */
#include "vector.h"
#include <math.h>

/** Returns the length (magnitude) of v: square x, y, z; sum
 *  the results, then return the square root.
 */
double vec_len(vector v) 
{
}

/** Returns a new vector whose components are normalized against v's.
 *  Take each x, y, z of v and divide by the length of v for each.
 */
vector vec_normalize(vector v) 
{
}

/** Returns a new vector whose components are multiplied by some 
 *  constant, scale: scale * x, scale * y, scale * z.
 */
vector vec_scale(vector v, double scale) 
{
}

/** Returns the dot product of two vectors v1 dot v2: (x1 * x2) + 
 *  (y1 * y2) + (z1 * z2).
 */
double vec_dot(vector v1, vector v2) 
{
}

/** Returns a new vector that is the sum of v1 + v2: x1 + x2, 
 *  y1 + y2, z1 + z2.
 */
vector vec_add(vector v1, vector v2) 
{
}

/** Returns a new vector that is the difference of v1 - v2:
 *  x1 - x2, y1 - y2, z1 - z2.
 */
vector vec_subtract(vector v1, vector v2) 
{
}

/** Copies the components of vector v into result_v. Note: realize that 
 *  result_v is a pointer to a vector_t. Use C's to '->' operator to 
 *  access the fields of result_v.
 */
void vec_copy(vector *result_v, vector v) 
{
}

/** Prints a string representation of vector v to stdout */
void vec_print(char *label, vector v) 
{
}




