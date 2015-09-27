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
    int length;
} list;

list* list_create();
void list_append(list* l, void* item);
void list_remove_last(list* l);
void list_remove_first(list* l);
void list_copy(list* l, list* out);

#endif
