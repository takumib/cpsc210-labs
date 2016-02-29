#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(void*);
    void reset();
    void* getCurItem();

private:
    Node* head;
    Node* current;
};

#endif
