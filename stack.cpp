#ifndef STACK_H
#define STACK_H
#include "stack.h"

template <typename T>
Stack<T>::Stack() : list()
{
    // Stack constructor
    // The underlying list is initialized automatically
}


template <typename T>
Stack<T>::Stack(Stack<T>& otherStack) : list(otherStack.list)
{
    // Implement the copy constructor for Stack
    // The underlying list is copied from otherStack.list
}

template <typename T>
Stack<T>::~Stack()
{
    // Stack destructor
    // List destructor will automatically be called
}

template <typename T>
void Stack<T>::Push(T item)
{
    list.InsertAtHead(item);
}

template <typename T>
T Stack<T>::Peek()
{
    Node<T>* topNode = list.GetHead();
    if (topNode != nullptr) {
        return topNode->GetValue();
    }
    return T();
}

template <typename T>
T Stack<T>::Pop()
{
    T item = Peek();
    list.DeleteHead();
    return item;
}

template <typename T>
int Stack<T>::Length()
{
    return list.Length();
}
#endif // STACK_H