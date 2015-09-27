#include <stdio.h>

#include "list.h"
#include "iterator.h"

int main()
{
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

    return 0;
}
