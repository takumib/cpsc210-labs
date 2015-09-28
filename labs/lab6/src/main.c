#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "iterator.h"

int main()
{
    list* list1 = list_create();
    list* list2 = list_create();
    list* list3 = list_create();

    int data[] = {1, 2, 3, 4, 5};
    char* strings[] = {"a", "b", "c", "d", "e", "f"};

    int data_size = 5;
    for(int i = 0; i < data_size; i++) {
        list_append(list1, &data[i]);
    }

    int string_size = 6;
    for(int i = 0; i < string_size; i++) {
        list_append(list2, strings[i]);
    }

    iterator* iter1 = iter_create(list1);

    printf("Data List Print Test....\n");

    printf("Data List: ");
    while(!iter_at_end(iter1)) {
        node* n = iter_get(iter1);
        int* val = n->data;
        printf("%d ", *val);
        iter_advance(iter1);
    }
    printf("\n");

    printf("Removing 2nd Element From Data\n");
    iter1 = iter_create(list1);
    iter_advance(iter1);
    iter_remove(iter1);

    printf("Data List: ");
    while(!iter_at_end(iter1)) {
        node* n = iter_get(iter1);
        int* val = n->data;
        printf("%d ", *val);
        iter_advance(iter1);
    }
    printf("\n");

    printf("\n");
    printf("String List Print Test.......\n");

    iterator* iter2 = iter_create(list2);

    printf("Strings List: ");
    while(!iter_at_end(iter2)) {
        node* n = iter_get(iter2);
        char* val = n->data;
        printf("%s ", val);
        iter_advance(iter2);
    }
    printf("\n");

    list_remove_last(list2);

    iter2 = iter_create(list2);
    printf("Removing Last Element from String List\n");
    printf("Strings List: ");
    while(!iter_at_end(iter2)) {
        node* n = iter_get(iter2);
        char* val = n->data;
        printf("%s ", val);
        iter_advance(iter2);
    }
    printf("\n");

    printf("\n");
    printf("Done Printing\n");

    return 0;
}
