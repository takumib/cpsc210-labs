/** list.h -- cpsc 210 lab 5 
 *  name:
 *  lab-section:
 */
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** list node  */
typedef struct node_t {
   struct node_t *next;	// pointer to the next node
   void *data; 			// the data stored at this node
} node;

/** list controller */
typedef struct list_t {
   node *current; 	// current list position 
   node *head;		// the head (start) of our list
} list;

/** function prototypes */
list *init();
void prepend(list *l, void *data);
void reset(list *l);
void *getnext(list *l);

#endif