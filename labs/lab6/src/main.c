#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include "list.h"
#include "iterator.h"

void list_create_test();
void list_append_test();
void list_remove_first_test();
void printGreen(char*);
void printRed(char*);

int main()
{
    list_create_test();
    list_append_test();
    list_remove_first_test();

    return 0;
}

void list_create_test()
{
    list* list = list_create();
    if(list != NULL) {
        free(list);
        printf("[list_create_test: ");
        printGreen("PASSED");
        printf("]\n");
    } else {
        printf("[list_create_test: ");
        printRed("FAILED");
        printf("]\n");
        exit(-1);
    }
}

void list_append_test()
{
    list* l = list_create();
    int x = 1;
    
    list_append(l, &x);

    if(l->head != NULL) {
       printf("[list_append_test1: "); 
       printGreen("PASSED");
       printf("]\n");
    } else {
        printf("[list_append_test1: ");
        printRed("FAILED");
        printf("]\n");
        exit(-1);
    }

    free(l->head);
    free(l);
}

void list_remove_first_test()
{
    list* l = list_create();
    int x = 0;

    list_append(l, &x);
    list_remove_first(l);

    if(l->head == NULL) {
        printf("[list_remove_first_test1: "); 
        printGreen("PASSED");
        printf("]\n");
    } else {
        printf("[list_remove_first_test1: ");
        printRed("FAILED");
        printf("]\n");
        exit(-1);
    }
}

void printGreen(char* msg)
{
    printf("\x1b[1m\x1b[32m%s\x1b[0m", msg);
}

void printRed(char* msg)
{
    printf("\x1b[1m\x1b[31m%s\x1b[0m", msg);
}
