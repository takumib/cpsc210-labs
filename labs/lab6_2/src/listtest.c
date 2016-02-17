/** listtest.c -- cpsc 210 lab 5 
 *  name:
 *  lab-section:
 */
#include <stdio.h>

#include "list.h"
#include "iterator.h"

typedef struct car_t {
    char *make;
    char *model;
    int year;
} car;

int main() {
    int data[] = {5, 10, 15, 20, 25};
 
    char *fruit[] = {"apple", "orange", "peach", "banana"};

    car cars[] = {{"Ford", "Mustang", 2009},
                  {"Honda", "Accord", 2010},
                  {"Toyota", "Camry", 2010}};

    int index;
    int size;

    int *ptr1;
    char *ptr2;
    car *ptr3;

    list *list1, *list2, *list3;
            
    //initialize our lists        
    list1 = list_create();
    list2 = list_create();
    list3 = list_create();
    
    //populate each list with the datasets defined above
    size = 5;
    for(index = 0; index < size; index++) {
        list_addFirst(list1, &data[index]);
    }

    for(index = 0; index < 4; index++) {
        list_addFirst(list2, fruit[index]);
    }

    for(index = 0; index < 3; index++) {
        list_addFirst(list3, &cars[index]);
    }

    //PRINTING SECTION
    printf("\n");
    list_reset(list1);
    iterator* iter1 = iter_create(list1);
    while(!iter_at_end(iter1)) {
        node* n = iter_get(iter1);
        int* val = n->data;
        printf("%d ", *val);
        iter_advance(iter1);
    }

    printf("\n");
    list_reset(list2);
    iterator* iter2 = iter_create(list2);
    while(!iter_at_end(iter2)) {
        node* n = iter_get(iter2);
        char* val = n->data;
        printf("%s ", val);
        iter_advance(iter2);
    }

    printf("\n");
    list_reset(list3);
    iterator* iter3 = iter_create(list3);
    while(!iter_at_end(iter3)) {
        node* n = iter_get(iter3);
        car* val = n->data;
        printf("[%s, %s, %d]\n", val->make, val->model, val->year);
        iter_advance(iter3);
    }
    printf("\n");
    
    return 0;
}
