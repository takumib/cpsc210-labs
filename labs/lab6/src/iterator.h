#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct iterator_t {
    list* l;
    node* current; 
} iterator;

iterator* iter_create(list* l);
void iter_advance(iterator* iter);
void* iter_next(iterator* iter);
void* iter_prev(iterator* iter);
int iter_at_end(iterator* iter);
node* iter_get(iterator* iter);
void iter_remove(iterator* iter);

#endif
