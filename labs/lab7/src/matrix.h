/*
 * File: matrix.h
 * Description: matrix op prototypes
 */
#include <stdio.h>
#include <stdlib.h>

void matrix_print(char* label, double matrix[3][3]);

void matrix_copy(double m[3][3], double result[3][3]);

void matrix_sum(double m1[3][3], double m2[3][3], double result[3][3]);

void matrix_difference(double m1[3][3], double m2[3][3], double result[3][3]);

void matrix_multiply(double m1[3][3], double m2[3][3], double result[3][3]);

void matrix_scale(double m[3][3], double scale);

void matrix_transpose(double m[3][3]);

int matrix_is_symmetric(double m[3][3]);