/** vector.h -- cpsc 210 lab 4 
 *  name: 
 *  lab-section:
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <memory.h>

/** This header file contains our vector representation and some
 *  prototype operations on 3d vectors
 */
typedef struct vector_t {
	double x, y, z;
    //TODO: this needs three components: x, y, and z of type double
} vector;

/** Prototype operations */
double vec_len(vector  v);
vector vec_normalize(vector v);
vector vec_scale(vector v, double scale);
double vec_dot(vector v1, vector v2);
vector vec_add(vector  v1, vector v2);
vector vec_subtract(vector  v1, vector v2);
void vec_copy(vector *result_v, vector v);
void vec_print(char *label, vector v);

#endif

