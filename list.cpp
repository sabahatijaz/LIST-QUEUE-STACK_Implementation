#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include "list.h"

#include <iostream>
#include "list.h"

// Constructor
template <typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}

// Copy Constructor
template <typename T>
List<T>::List(List<T>& otherList)
{
    head = nullptr;
    tail = nullptr;

    Node<T>* current = otherList.head;
    while (current != nullptr) {
        InsertAtTail(current->GetValue());
        current = current->GetNext();
    }
}


// Destructor
template <typename T>
List<T>::~List()
{
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->GetNext();
        delete temp;
    }
    tail = nullptr;
}

// Insertion Functions

template <typename T>
void List<T>::InsertAtHead(T item)
{
    Node<T>* newNode = new Node<T>(item);
    newNode->SetNext(head);
    newNode->SetPrev(nullptr); // Initialize prev pointer to nullptr
    if (head != nullptr) {
        head->SetPrev(newNode);
    } else {
        // If the list was empty, also update the tail pointer
        tail = newNode;
    }
    head = newNode;
}

template <typename T>
void List<T>::InsertAtTail(T item)
{
    Node<T>* newNode = new Node<T>(item);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->SetPrev(tail);
        tail->SetNext(newNode);
        tail = newNode;
    }
}

template <typename T>
void List<T>::InsertAfter(T toInsert, T afterWhat)
{
    Node<T>* newNode = new Node<T>(toInsert);
    Node<T>* current = head;
    while (current != nullptr && current->GetValue() != afterWhat) {
        current = current->GetNext();
    }
    if (current != nullptr) {
        newNode->SetNext(current->GetNext());
        newNode->SetPrev(current);
        if (current->GetNext() != nullptr) {
            current->GetNext()->SetPrev(newNode);
        } else {
            // If current is the tail, update tail
            tail = newNode;
        }
        current->SetNext(newNode);
    } else {
        // Handle the case when afterWhat is not found in the list
        // Insert at the end of the list
        InsertAtTail(toInsert);
    }
}

// Lookup Functions

template <typename T>
Node<T>* List<T>::GetHead()
{
    return head;
}

template <typename T>
Node<T>* List<T>::GetTail()
{
    return tail;
}

template <typename T>
Node<T>* List<T>::SearchFor(T item)
{
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->GetValue() == item) {
            return current;
        }
        current = current->GetNext();
    }
    return nullptr; // Not found
}

// Deletion Functions

template <typename T>
void List<T>::DeleteElement(T item)
{
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->GetValue() == item) {
            if (current->GetPrev() != nullptr) {
                current->GetPrev()->SetNext(current->GetNext());
            } else {
                // If current is the head, update head
                head = current->GetNext();
            }
            if (current->GetNext() != nullptr) {
                current->GetNext()->SetPrev(current->GetPrev());
            } else {
                // If current is the tail, update tail
                tail = current->GetPrev();
            }
            delete current;
            return;
        }
        current = current->GetNext();
    }
}

template <typename T>
void List<T>::DeleteHead()
{
    if (head != nullptr) {
        Node<T>* temp = head;
        head = head->GetNext();
        if (head != nullptr) {
            head->SetPrev(nullptr);
        } else {
            // If head is the only node, update tail
            tail = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void List<T>::DeleteTail()
{
    if (tail != nullptr) {
        Node<T>* temp = tail;
        tail = tail->GetPrev();
        if (tail != nullptr) {
            tail->SetNext(nullptr);
        } else {
            // If tail is the only node, update head
            head = nullptr;
        }
        delete temp;
    }
}

// Utility Functions

template <typename T>
int List<T>::Length()
{
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        count++;
        current = current->GetNext();
    }
    return count;
}

// // Explicit instantiation of supported types
template class List<int>;
template class List<double>;
template class List<std::string>;

#endif // LIST_H