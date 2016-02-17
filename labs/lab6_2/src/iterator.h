/*
 * Author: Takumi Bolte
 * Last Edited: September 28, 2015
 * File: iterator.h
 * Description: iterator header file.
 */
#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct iterator_t {
    list* l;
    node* current; 
} iterator;

iterator* iter_create(list* l);
void iter_advance(iterator* iter);
int iter_at_end(iterator* iter);
node* iter_get(iterator* iter);

#endif
