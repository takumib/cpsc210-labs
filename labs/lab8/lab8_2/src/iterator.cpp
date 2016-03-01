#include "iterator.h"

#include <cstring>

/*
 * Default Iterator constructor.
 * Hint: set all member variables to NULL.
 */
Iterator::Iterator()
{}

/*
 * Specialized Iterator constructor.
 * Hint: Use the constructor argument to initialize the Iterator.
 */
Iterator::Iterator(List* l)
{}

/*
 * Iterator destructor.
 */
Iterator::~Iterator()
{
    // left blank intentionally.
}

/*
 * Advances the iterator to the Node's next.
 * Hint: same concept as the C version.
 */
void Iterator::advance()
{
}

/*
 * Returns true if the current Node's next is not NULL.
 * Hint: similar to C version, except we are looking at
 * the current's next not current.
 */
bool Iterator::hasNext()
{
    return false;
}

/*
 * Returns the current Node.
 */
Node* Iterator::get()
{
    return NULL;
}
