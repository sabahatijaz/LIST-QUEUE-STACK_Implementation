#ifndef __QUEUE_H
#define __QUEUE_H
#include "list.cpp"

/* This is the generic Queue class */
template <typename T>
class Queue
{
    List<T> list;

public:

    // Constructor
    Queue();

    // Copy Constructor
    Queue(Queue<T>& otherQueue);

    // Destructor
    ~Queue();

    // Required Methods
    void Enqueue(T item);
    T Peek();
    T Dequeue();
    int Length();
};

#endif