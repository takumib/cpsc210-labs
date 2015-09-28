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
    struct node_t* prev;
    void* data;
} node;

typedef struct list_t {
    node* head;
    node* tail;
} list;

list* list_create();
void list_append(list* l, void* item);
void list_remove_last(list* l);
void list_remove_first(list* l);

#endif
