#ifndef LIST_H
#define LIST_H

#include "node.h"

template<typename T>
class List {
public:
    List();
    ~List();

    void addFirst(T);
    void reset();
    T getCurItem();
    Node<T>* getHead();

private:
    Node<T>* head;
    Node<T>* current;
};

#endif
