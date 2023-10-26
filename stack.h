#ifndef __STACK_H
#define __STACK_H
#include "list.cpp"

/* This is the generic Stack class */
template <typename T>
class Stack
{
    List<T> list;

public:

    // Constructor
    Stack();

    // Copy Constructor
    Stack(Stack<T>& otherStack);

    // Destructor
    ~Stack();

    // Required Methods
    void Push(T item);
    T Peek();
    T Pop();
    int Length();
};

#endif