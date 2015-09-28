/*
 * Author: Takumi Bolte
 * Last Edited: September 28, 2015
 * File: test.c
 * Description: small test engine for linked list and iterator operations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "iterator.h"

void list_create_test();
void list_append_test();
void list_remove_first_test();
void list_remove_last_test();

void iterator_create_test();
void iterator_advance_test();
void iterator_get_test();
void iterator_next_test();
void iterator_prev_test();
void iterator_at_end_test();
void iterator_remove_test();

void print_passed_test(char*);
void print_passed_test2(char*, int, int);
void print_failed_test(char*);
void print_failed_test2(char*, int, int);
void set_green(char str[], char*);
void set_red(char str[], char*);

int main()
{
    printf("Testing....\n");
    printf("--------------------\n");
    printf("| Testing: list.c  |\n");
    printf("--------------------\n");
    list_create_test();
    list_append_test();
    list_remove_first_test();
    list_remove_last_test();

    printf("\n");
    printf("------------------------\n");
    printf("| Testing: iterator.c  |\n");
    printf("------------------------\n");
    iterator_create_test();
    iterator_advance_test();
    iterator_get_test();
    iterator_next_test();
    iterator_prev_test();
    iterator_at_end_test();
    iterator_remove_test();

    printf("\n");
    printf("Done running tests\n");

    return 0;
}

void list_create_test()
{
    char* test = "list_create_test";

    list* list = list_create();
    if(list != NULL) {
        free(list);
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void list_append_test()
{
    char* test = "list_append_test";

    list* l = list_create();
    int x = 1;
    
    list_append(l, &x);

    if(l->head != NULL) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }

    free(l->head);
    free(l);
}

void list_remove_first_test()
{
    char* test = "list_remove_first_test1";
    list* l = list_create();
    int x = 0;

    list_append(l, &x);
    list_remove_first(l);

    if(l->head == NULL) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void list_remove_last_test()
{
    char* test = "list_remove_last_test";

    list* l = list_create();
    int x = 1;

    list_append(l, &x);
    list_remove_last(l);

    if(l->tail == NULL) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void iterator_create_test()
{
    char* test = "iterator_create_test";
    
    list* list = list_create();
    iterator* iter = iter_create(list);

    if(iter != NULL) {
        free(iter);
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void iterator_advance_test()
{
    char* test = "iterator_advance_test";

    list* list = list_create();
    int x = 1;
    int y = 2;

    list_append(list, &x);
    list_append(list, &y);

    iterator* iter = iter_create(list);

    iter_advance(iter);

    if(iter->current != NULL) {
        int* cur = iter->current->data;
        if(*cur == y) {
            print_passed_test2(test, y, *cur);
        } else {
            print_failed_test2(test, y, *cur);
        }
    } else {
        print_failed_test(test);
    }
}

void iterator_next_test()
{
    char* test = "iterator_next_test1";
    char* test2 = "iterator_next_test2";

    list* list = list_create();
    int x = 1;
    int y = 2;

    list_append(list, &x);
    list_append(list, &y);

    iterator* iter = iter_create(list);

    int* cur = iter_next(iter);

    if(iter->current != NULL) {
        int* next = iter->current->data;
        if(*cur == x) {
            print_passed_test2(test, x, *cur);
        } else {
            print_failed_test2(test, x, *cur);
            exit(-1);
        }
        if(*next == y) {
            print_passed_test2(test2, y, *next);
        } else {
            print_failed_test2(test2, y, *next);
            exit(-1);
        }
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void iterator_prev_test()
{
    char* test = "iterator_prev_test1";
    char* test2 = "iterator_prev_test2";

    list* list = list_create();
    int x = 1;
    int y = 2;

    list_append(list, &x);
    list_append(list, &y);

    iterator* iter = iter_create(list);

    iter_next(iter);
    int* cur = iter_prev(iter);

    if(iter->current != NULL) {
        int* next = iter->current->data;
        if(*cur == y) {
            print_passed_test2(test, y, *cur);
        } else {
            print_failed_test2(test, y, *cur);
        }
        if(*next == x) {
            print_passed_test2(test2, x, *next);
        } else {
            print_failed_test2(test2, x, *next);
        }
    } else {
        print_failed_test(test);
    }
}

void iterator_at_end_test()
{
    char* test = "iterator_at_end_test";

    list* list = list_create();
    int x = 1;
    int y = 2;

    list_append(list, &x);
    list_append(list, &y);

    iterator* iter = iter_create(list);

    iter_advance(iter);
    iter_advance(iter);

    if(iter_at_end(iter)) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void iterator_get_test() 
{
    char* test = "iterator_get_test";

    list* list = list_create();
    int x = 1;
    int y = 2;

    list_append(list, &x);
    list_append(list, &y);

    iterator* iter = iter_create(list);

    iter_advance(iter);

    if(iter->current != NULL) {
        node* cur = iter_get(iter);
        int* val = cur->data;
        if(*val == y) {
            print_passed_test2(test, y, *val);
        } else {
            print_failed_test2(test, y, *val);
            exit(-1);
        }
    } else {
        print_failed_test(test);
        exit(-1);
    }
}

void iterator_remove_test() 
{
    char* test = "iterator_remove_test";
    char* test2 = "iterator_remove_test2";

    list* l = list_create();
    int x = 1;

    list_append(l, &x);

    iterator* iter = iter_create(l);

    iter_remove(iter);

    if(iter->current == NULL) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        exit(-1);
    }

    list* l2 = list_create();
    int y = 2;
    int z = 3;

    list_append(l2, &y);
    list_append(l2, &z); 

    iter = iter_create(l2);

    iter_advance(iter);
    iter_remove(iter);

    if(iter->current != NULL) {
        node* cur = iter_get(iter);
        int* val = cur->data;
        if(*val == y) {
            print_passed_test2(test2, y, *val);
        } else {
            print_failed_test2(test2, y, *val);
            exit(-1);
        }
    } else {
        print_failed_test(test2);
        exit(-1);
    }
}

void print_passed_test(char* msg)
{
    char str[128];
    set_green(str, "PASSED");
    
    printf("[%s: %s]\n", msg, str);
}

void print_passed_test2(char* msg, int exp, int act)
{
    char str[128];
    set_green(str, "PASSED");
    
    printf("[%s: %s] [Expected: %d Actual: %d]\n", msg, str, exp, act);
}

void print_failed_test(char* msg)
{
    char str[128];
    set_red(str, "FAILED");
    
    printf("[%s: %s]\n", msg, str);
}

void print_failed_test2(char* msg, int exp, int act)
{
    char str[128];
    set_red(str, "FAILED");
    
    printf("[%s: %s] [Expected: %d Actual: %d]\n", msg, str, exp, act);
}

void set_green(char ret[], char* msg)
{
    char* green = "\x1b[1m\x1b[32m";
    char* reset = "\x1b[0m";

    strcpy(ret, green);
    strcat(ret, msg);
    strcat(ret, reset);
}

void set_red(char ret[], char* msg)
{
    char* red = "\x1b[1m\x1b[31m";
    char* reset = "\x1b[0m";

    strcpy(ret, red);
    strcat(ret, msg);
    strcat(ret, reset);
}
