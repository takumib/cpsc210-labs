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
void print_debug(char*);
void set_green(char str[], char*);
void set_red(char str[], char*);
void set_yellow(char str[], char*);

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

    list* l = list_create();
    if(l != NULL) {
        if(l->head != NULL || l->tail != NULL) {
            print_failed_test(test);
            print_debug("did not initialize correctly");
            exit(-1);
        }
        free(l);
        print_passed_test(test);
    } else {
        print_failed_test(test);
        print_debug("returned NULL");
        exit(-1);
    }
}

void list_append_test()
{
    char* test = "list_append_once_test";
    char* test2 = "list_append_multiple_test";

    list* l = list_create();
    int x = 1;
    
    list_append(l, &x);

    if(l->head != NULL && l->tail != NULL) {
        if(l->head->prev != NULL || l->head->next != NULL) {
            print_failed_test(test);
            print_debug("initializing prev and next failed");
            exit(-1);
        }

        int* head_val = l->head->data;
        int* tail_val = l->tail->data;

        if(*head_val != x || *tail_val != x) {
            print_failed_test(test);
            print_debug("appending node failed");
            exit(-1);
        }
        print_passed_test(test);
    } else {
        print_failed_test(test);
        print_debug("appending an empty list failed");
        exit(-1);
    }

    free(l->head);
    free(l);

    list* l2 = list_create();
    int y = 2;
    int z = 3;

    list_append(l2, &y);
    list_append(l2, &z);

    if(l2->head != NULL && l2->tail != NULL) {
        if(l2->head->next == NULL || l2->tail->prev == NULL) {
            print_failed_test(test2);
            print_debug("added new node incorrectly");
            exit(-1);
        }

        int* head_next = l2->head->next->data;
        int* tail_prev = l2->tail->prev->data;
        int* tail = l2->tail->data;

        if(*head_next != z) {
            print_failed_test(test2);
            print_debug("setting old tail's next failed");
            exit(-1);
        }

        if(*tail != z) {
            print_failed_test(test2);
            print_debug("setting tail failed");
            exit(-1);
        }

        if(*tail_prev != y) {
            print_failed_test(test2);
            print_debug("setting tail's prev failed");
            exit(-1);
        }
        print_passed_test(test2);
    } else {
        print_failed_test(test2);
        print_debug("appending list failed");
        exit(-1);
    }
}

void list_remove_first_test()
{
    char* test = "list_remove_first_one_element_test";
    char* test2 = "list_remove_first_multiple_element_test";
    list* l = list_create();
    int x = 1;

    list_append(l, &x);
    list_remove_first(l);

    if(l->head == NULL) {
        print_passed_test(test);
    } else {
        print_failed_test(test);
        print_debug("did not remove correctly");
        exit(-1);
    }

    list* l2 = list_create();
    int y = 2;
    int z = 3;

    list_append(l2, &y);
    list_append(l2, &z);

    list_remove_first(l2);
    if(l2->head != NULL) {
        int* head_val = l2->head->data;
        if(*head_val != z) {
            print_failed_test(test2);
            print_debug("did not update head correctly");
            exit(-1);
        }
        print_passed_test(test2);
    } else {
        print_failed_test(test2);
        print_debug("did not remove correctly");
        exit(-1);
    }

}

void list_remove_last_test()
{
    char* test = "list_remove_last_one_element_test";
    char* test2 = "list_remove_last_multiple_element_test";

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

    list* l2 = list_create();
    int y = 2;
    int z = 3;

    list_append(l2, &y);
    list_append(l2, &z);

    list_remove_last(l2);
    if(l2->tail != NULL) {
        int* tail_val = l2->tail->data;
        if(*tail_val != y) {
            print_failed_test(test2);
            print_debug("did not update head correctly");
            exit(-1);
        }
        print_passed_test(test2);
    } else {
        print_failed_test(test2);
        print_debug("did not remove correctly");
        exit(-1);
    }
}

void iterator_create_test()
{
    char* test = "iterator_create_test";
    
    list* list = list_create();
    iterator* iter = iter_create(list);

    if(iter != NULL) {
        if(iter->l != list || iter->current != list->head) {
            print_failed_test(test);
            print_debug("did not initialize iterator correctly");
            exit(-1);
        }

        free(iter);
        print_passed_test(test);
    } else {
        print_failed_test(test);
        print_debug("did not allocate iterator correctly");
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
            print_debug("did not advance correctly");
            exit(-1);
        }
    } else {
        print_failed_test(test);
        print_debug("did not advance correctly");
        exit(-1);
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
        if(next == NULL || cur == NULL) {
            print_failed_test(test);
            print_debug("returned NULL");
            exit(-1);
        }
        if(*cur == x) {
            print_passed_test2(test, x, *cur);
        } else {
            print_failed_test2(test, x, *cur);
            print_debug("old cur data does not match");
            exit(-1);
        }
        if(*next == y) {
            print_passed_test2(test2, y, *next);
        } else {
            print_failed_test2(test2, y, *next);
            print_debug("new cur data did not match");
            exit(-1);
        }
    } else {
        print_failed_test(test);
        print_debug("get next did not return correct pointer");
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
        if(cur == NULL || next == NULL) {
            print_failed_test(test);
            print_debug("returned NULL");
            exit(-1);
        }
        if(*cur == y) {
            print_passed_test2(test, y, *cur);
        } else {
            print_failed_test2(test, y, *cur);
            print_debug("old current does not match");
            exit(-1);
        }
        if(*next == x) {
            print_passed_test2(test2, x, *next);
        } else {
            print_failed_test2(test2, x, *next);
            print_debug("new current does not match");
            exit(-1);
        }
    } else {
        print_failed_test(test);
        print_debug("did not set previous correctly");
        exit(-1);
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
        print_debug("did not correctly check end");
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
        if(cur == NULL) {
            print_failed_test(test);
            print_debug("return was NULL");
            exit(-1);
        }
        int* val = cur->data;
        if(*val == y) {
            print_passed_test2(test, y, *val);
        } else {
            print_failed_test2(test, y, *val);
            print_debug("get did not match input");
            exit(-1);
        }
    } else {
        print_failed_test(test);
        print_debug("did not get current pointer");
        exit(-1);
    }
}

void iterator_remove_test() 
{
    char* test = "iterator_remove_one_element_test";
    char* test2 = "iterator_remove_multiple_element_test";

    list* l = list_create();
    int x = 1;

    list_append(l, &x);

    iterator* iter = iter_create(l);

    iter_remove(iter);

    if(iter->current == NULL) {
        if(l->head != NULL) {
            print_failed_test(test);
            print_debug("did not update head properly");
            exit(-1);
        }
        print_passed_test(test);
    } else {
        print_failed_test(test);
        print_debug("did not remove correctly");
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
        if(cur == NULL) {
            print_failed_test(test2);
            print_debug("did not update cur pointer");
            exit(-1);
        }
        int* val = cur->data;
        if(*val == y) {
            print_passed_test2(test2, y, *val);
        } else {
            print_failed_test2(test2, y, *val);
            print_debug("new cur is not same as input");
            exit(-1);
        }
    } else {
        print_failed_test(test2);
        print_debug("did not remove properly");
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

void print_debug(char* msg)
{
    char str[128];
    set_yellow(str, "ERROR");
    
    printf("-> [%s: %s]\n", str, msg);
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

void set_yellow(char ret[], char* msg)
{
    char* yellow = "\x1b[1m\x1b[33m";
    char* reset = "\x1b[0m";

    strcpy(ret, yellow);
    strcat(ret, msg);
    strcat(ret, reset);
}
