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

   veh_t vehicles[] = { {"Ford", "Mustang", 2009},
                        {"Honda", "Accord", 2010},
                        {"Toyota", "Camry", 2010},
                        {"Jeep", "Cherokee", 2004},
                        {"Chevrolet", "Impala", 2007},
                        {"Nissan", "Altima", 2006},
                        {"Dodge", "Caravan", 2003}};

   int index;
   int size;

   int   *ptr1;
   char  *ptr2;
   veh_t *ptr3;

   list_t *list1;
   list_t *list2;
   list_t *list3;

   /*iterator_t *iter1;
   iterator_t *iter2;
   iterator_t *iter3;*/
                        
   // create some lists
   list1 = list_init();
   list2 = list_init();
   list3 = list_init();

   // fill them up
/*   size = sizeof(data)/sizeof(int);
   for(index = 0; index < size; index++) {
      list_add(list1, &data[index]);
   }

   size = sizeof(fruit)/sizeof(char *);
   for(index = 0; index < size; index++) {
      list_add(list2, fruit[index]);
   }
   
   size = sizeof(vehicles)/sizeof(veh_t);
   for(index = 0; index < size; index++) {
      list_add(list3, &vehicles[index]);
   }

   // get the data out and print it

   fprintf(stdout, "List 1: ");
   iter1 = newIterator(list1);
   while(list_hasnext(iter1)) {
      ptr1 = list_next(iter1);
      fprintf(stdout, "%d, ", *ptr1);
   }
   fprintf(stdout, "\n");
   fprintf(stdout, "\nTest list_begin() function: ");

   // test 
   list_begin(iter1);
   ptr1 = list_next(iter1);
   fprintf(stdout, "First value=%d\n", *ptr1);

   fprintf(stdout, "\nList 2: ");

   fprintf(stdout, "\nList 3: ");

   fprintf(stdout, "\n\n");*/
   return 0;
}
