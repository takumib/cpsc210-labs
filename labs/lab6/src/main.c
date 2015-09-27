#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "list.h"
#include "iterator.h"

void list_create_test();

int main()
{
    list_create_test();
    /*
    list* l = list_create(); 

    int data[4] = {0, 1, 2, 3};

    for(int i = 0; i < 4; i++) {
        list_append(l, &data[i]);
    }

    iterator* iter = iter_create(l);

    void* n = iter_next(iter);
    printf("%d, ", *((int*)n));
    
    iter_remove(iter);
    n = iter_next(iter);
    printf("%d, ", *((int*)n));
    
    printf("\n");

    iter = iter_create(l);
    n = iter_next(iter);
    printf("%d, ", *((int*)n));
    n = iter_next(iter);
    printf("%d, ", *((int*)n));
    printf("\n");

    printf("\n");
    */

    return 0;
}

void list_create_test()
{
    list* list = list_create();
    if(list != NULL) {
        free(list);
        printf("[list_create_test: PASSED]\n");
    } else {
        printf("list_create_test: FAILED]\n");
    }
}
