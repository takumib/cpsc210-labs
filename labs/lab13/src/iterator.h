#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"
#include "node.h"

template<typename T>
class Iterator {
public:
    Iterator();
    Iterator(List<T>*);
    ~Iterator();

    void advance();
    bool hasNext();
    Node<T>* get();

private:
    List<T>* list;
    Node<T>* current;
};

#endif
