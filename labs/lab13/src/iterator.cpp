#include "iterator.h"

#include <cstring>
#include <string>

/*
 * Default Iterator constructor.
 * Hint: set all member variables to NULL.
 */
template<typename T>
Iterator<T>::Iterator()
{
    list = NULL;
    current = NULL;
}

/*
 * Specialized Iterator constructor.
 * Hint: Use the constructor argument to initialize the Iterator.
 */
template<typename T>
Iterator<T>::Iterator(List<T>* l)
{
    list = l;
    current = l->getHead();
}

/*
 * Iterator destructor.
 */
template<typename T>
Iterator<T>::~Iterator()
{
    // left blank intentionally.
}

/*
 * Advances the iterator to the Node's next.
 * Hint: same concept as the C version.
 */
template<typename T>
void Iterator<T>::advance()
{
    current = current->getNext();
}

/*
 * Returns true if the current Node's next is not NULL.
 * Hint: similar to C version, except we are looking at
 * the current's next not current.
 */
template<typename T>
bool Iterator<T>::hasNext()
{
    return current != NULL;
}

/*
 * Returns the current Node.
 */
template<typename T>
Node<T>* Iterator<T>::get()
{
    return current;
}

template class Iterator<int>;
