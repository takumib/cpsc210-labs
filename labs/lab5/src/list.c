/** list implementation -- cpsc 2101 lab 5 */

#include "list.h"

list_t *init() {
    return (list_t*)malloc(sizeof(list_t));
}

void prepend(list_t *list, void *data) {

	//Incorrect: the specification asks us to prepend, not append.
	/*node_t* addition = (node_t*)malloc(sizeof(node_t));
	addition->data = data;
	
	if (list->head == NULL) {
		list->head = addition;
		list->current = addition;
	}
	else {
		list->current->next = addition;
		list->current = addition;
	}*/
}

void reset(list_t *list) {

}

void* next(list_t *list) {

}