#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"


template <typename T>
Queue<T>::Queue() : list()
{
    // Queue constructor
    // The underlying list is initialized automatically
}

template <typename T>
Queue<T>::Queue(Queue<T>& otherQueue) : list(otherQueue.list)
{
    // Implement the copy constructor for Queue
    // need to copy the elements from otherQueue.list to this->list
    // Assume List class has an InsertAtTail method
    Node<T>* current = otherQueue.list.GetHead();
    while (current != nullptr) {
        list.InsertAtTail(current->GetValue());
        current = current->GetNext();
    }
}


template <typename T>
Queue<T>::~Queue()
{
    // Queue destructor
    // List destructor will automatically be called
}

template <typename T>
void Queue<T>::Enqueue(T item)
{
    list.InsertAtTail(item);
}

template <typename T>
T Queue<T>::Peek()
{
    Node<T>* headNode = list.GetHead();
    if (headNode != nullptr) {
        return headNode->GetValue();
    }
    return T();
}


template <typename T>
T Queue<T>::Dequeue()
{
    if (list.Length() == 0) {
        
        return T();
    }

    T item = list.GetHead()->GetValue();
    list.DeleteHead();
    return item;
}


template <typename T>
int Queue<T>::Length()
{
    return list.Length();
}
#endif // QUEUE_H