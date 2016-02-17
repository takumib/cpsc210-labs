/*
 * Author: Takumi Bolte
 * Last Edited: September 28, 2015
 * File: list.h
 * Description: linked list header file.
 */
#ifndef LIST_H
#define LIST_H

typedef struct node_t {
    struct node_t* next;
    void* data;
} node;

typedef struct list_t {
    node* current;
    node* head;
} list;

list* list_create();
void list_addFirst(list* l, void* item);
void list_reset(list* l);
void *list_getnext(list* l);

#endif
