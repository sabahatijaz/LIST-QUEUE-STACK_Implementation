#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>

/* This class just holds a single data item. */
template <typename T>
class Node
{
  private:
    T value;
    Node<T> *next;
    Node<T> *prev;
  public:
    Node(T theVal)
    {
        this->value = theVal;
        this->next = NULL;
        this->prev = NULL;
    }
    T GetValue()
    {
        return value;
    }
    Node<T>* GetNext()
    {
        return next;
    }
    Node<T>* GetPrev()
    {
        return prev;
    }
    void SetValue(T theVal)
    {
    	this->value = theVal;
    }
    void SetNext(Node<T>* n)
    {
        this->next = n;
    }
    void SetPrev(Node<T>* p)
    {
        this->prev = p;
    }
};

/* This is the generic List class */
template <typename T>
class List
{
    Node<T> *head;
    Node<T> *tail;
public:

    // Constructor
    List();

    // Copy Constructor
    List(List<T>& otherList);

    // Destructor
    ~List();

    // Insertion Functions
    void InsertAtHead(T item);
    void InsertAtTail(T item);
    void InsertAfter(T toInsert, T afterWhat);

    // Lookup Functions
    Node<T> *GetHead();
    Node<T> *GetTail();
    Node<T> *SearchFor(T item);

    // Deletion Functions
    void DeleteElement(T item);
    void DeleteHead();
    void DeleteTail();

    // Utility Functions
    int Length();
};

#endif