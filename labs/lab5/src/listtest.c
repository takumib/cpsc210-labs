/** listtest.c -- cpsc 210 lab 5 
 *  name:
 *  lab-section:
 */
#include "list.h"

typedef struct vehicle_type {
	char *make;
	char *model;
	int year;
} veh_t;

int main() {
	int data[] = {5, 10, 15, 20, 25};
 
	char *fruit[] = {"apple", "orange", "peach", "banana"};

	veh_t vehicles[] = {{"Ford", "Mustang", 2009},
                        {"Honda", "Accord", 2010},
                        {"Toyota", "Camry", 2010}};

   	int index;
   	int size;

	int *ptr1;
	char *ptr2;
	veh_t *ptr3;

	list_t *list1, *list2, *list3;
            
    //initialize our lists        
	list1 = init();
	list2 = init();
	list3 = init();
	
	//populate each list with the datasets defined above
	size = sizeof(data)/sizeof(int);
	for (index = 0; index < size; index++) {
		prepend(list1, &data[index]);
	}
		//TODO: populate the fruit here

		//TODO: populate the vehicles here

	//PRINTING SECTION
	
		//TODO: print the numbers here

		//TODO: print the fruit here
	
		//TODO: print the vehicles here
	return 0;
}