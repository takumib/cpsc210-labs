#include "matrix.h"

int main() {

	double M1[3][3] = {{1, 2, 3}, 
					   {4, 5, 6},
					   {7, 8, 9}};
					  
	double M2[3][3] = {{2, 3, 4}, 
					   {5, 6, 7},
					   {8, 9, 0}};

	double M3[3][3];
	
	double M4[3][3] = {{2, 3, 4},
	  				   {3, 1, 5},
	  				   {4, 5, 6}};

	matrix_print("Matrix M1 is:\n", M1); 
	
	matrix_sum(M1, M2, M3);
	matrix_print("The sum of M1 and M2 is:\n", M3); 
		
	double M1_orig[3][3];
	matrix_copy(M1, M1_orig);	//copy M1 to M1_orig
		 
	matrix_scale(M1, 5);  		//mutate M1 by scaling by 5
	matrix_print("The result of scaling M1 by 5 is:\n", M1);

	matrix_copy(M1, M3);      	//copy scaled M1 to M3
	matrix_copy(M1_orig, M1);	//restore M1 to its pre-scaled state

	matrix_difference(M1, M2, M3);
	matrix_print("The difference between M1 and M2 is:\n", M3);

    matrix_multiply(M1, M2, M3);
    matrix_print("The product of M1 and M2 is:\n", M3);

   	matrix_transpose(M3);
   	matrix_print("The transpose of M3 is:\n", M3);
   	
   	int is_symmetric = matrix_is_symmetric(M3);
   	printf("Is matrix M3 symmetric? ... %s\n", is_symmetric == 0 ? "yes" : "naw" );
   	
   	is_symmetric = matrix_is_symmetric(M4);
   	printf("Is matrix M4 symmetric? ... %s\n", is_symmetric == 0 ? "yes" : "naw" );

   	return 0;
}


