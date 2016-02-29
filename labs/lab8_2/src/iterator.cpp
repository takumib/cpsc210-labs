#include "iterator.h"

Iterator::Iterator() :
    list(nullptr),
    current(nullptr)
{}

Iterator::Iterator(List* l) :
    list(l),
    current(l->head)
{}

Iterator::~Iterator()
{}

void Iterator::advance()
{
    current = current->getNext();
}

bool Iterator::hasNext()
{
    return current->getNext() == nullptr;
}

void Iterator::get()
{
    return current;
}

