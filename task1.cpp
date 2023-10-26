#include <cstdio>
#include <signal.h>
#include <iostream>
#include <string>
#include "list.cpp"
using namespace std;

int testno;
int totpoints;
int lastpoints;
int lasttotpoints;
int points;

void test_list_init()
{
    lasttotpoints = 0;

    List<int> a;
    cout << ".";

    List<string> b;
    cout << ".";

    List<List<int> > c;
    cout << ".";
    lastpoints = 5;
    lasttotpoints += 5;
}

void test_list_insert_head()
{
    lasttotpoints = 5;

    List<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.InsertAtHead(i);
        Node<int> *tmp = l.GetHead();
        int k = i;
        while (tmp != NULL)
        {
            if (tmp->GetValue() != k)
                int a = 1/0;
            k--;
            tmp = tmp->GetNext();
        }
    }
    cout << ".";

    lastpoints += 5;
}

void test_list_insert_tail()
{
    lasttotpoints = 10;

    List<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.InsertAtTail(i);
        Node<int> *tmp = l.GetTail();
        int k = i;
        while (tmp != NULL)
        {
            if (tmp->GetValue() != k)
                int a = 1/0;
            k--;
            tmp = tmp->GetPrev();
        }
    }
    cout << ".";

    lastpoints += 10;
}

void test_list_insert_after()
{
    lasttotpoints = 10;

    List<int> l;
    l.InsertAtHead(0);
    for (int i = 1; i < 25000; i++)
    {
        //l.Dump();
	l.InsertAfter(i, i-1);
	//l.Dump();
        Node<int> *tmp = l.SearchFor(i);
        if (tmp->GetNext() != NULL || tmp->GetPrev()->GetValue() != (i-1) || tmp->GetValue() != i)
            int a = 1/0;
    }
    cout << ".";

    lastpoints += 10;
}

void test_delete()
{
    lasttotpoints = 20;

    // Insert some items
    List<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.InsertAtHead(i);
    }

    // Delete the head a few times
    for (int i = 0; i < 50; i++)
        l.DeleteHead();
    cout << ".";
    lastpoints += 5;
    
    // Delete most of the items in the list
    while (l.Length() > 50)
    {
        Node<int> *tmp = l.GetHead();
        if (tmp != NULL)
            l.DeleteElement(tmp->GetValue());
        tmp = l.GetTail();
        if (tmp != NULL)
            l.DeleteElement(tmp->GetValue());
    }
    lastpoints += 10;
    cout << ".";

    // Delete the tail till we're done
    int max = l.Length();
    for (int i = 0; i < max; i++)
        l.DeleteTail();
    cout << ".";
    lastpoints += 5;

}

void test_copy()
{
    lasttotpoints = 5;

    List<int> l;
    for (int i = 0; i < 25000; i++)
    {
        l.InsertAtHead(i);
    }
    List<int> l2(l);
    List<int> l3;
    for (int i = 0; i < 25000; i++)
    {
        l3.InsertAtHead(i);
        l.DeleteHead();
    }

    Node<int> *tmp = l2.GetHead();
    int k = 24999;
    while (tmp != NULL)
    {
        if (tmp->GetValue() != k)
            int a = 1/0;
        k--;
        tmp = tmp->GetNext();
    }
    if (k != -1)
        int a = 1/0;

    cout << ".";

    lastpoints += 5;
}

// Test case dispatcher
void dispatcher()
{
    while (true)
    {
        lastpoints = 0;
        lasttotpoints = 0;
        switch (testno)
        {
            case 0:
                {
                    cout << "Testing List Initialization ";
                    test_list_init();
                }
                break;
            case 1:
                {
                    cout << "Testing Insertion at Head ";
                    test_list_insert_head();
                }
                break;
            case 2:
                {
                    cout << "Testing Insertion at Tail ";
                    test_list_insert_tail();
                }
                break;
            case 3:
                {
                    cout << "Testing Insertion After ";
                    test_list_insert_after();
                }
                break;
            case 4:
                {
                    cout << "Testing Delete ";
                    test_delete();
                }
                break;
            case 5:
                {
                    cout << "Testing Copy ";
                    test_copy();
                }
                break;
            default:
                {
                    cout << "Total Points: " << points << " / " << totpoints << endl;
                    exit(0);
                }
        }
        cout << " Passed! " << lastpoints << " / " << lasttotpoints << endl;
        testno++;
        points += lastpoints;
        totpoints += lasttotpoints;
    }
}

// Signal handler for exceptions
void signal_handler(int signum)
{
    cout << " Failed! " << lastpoints << " / " << lasttotpoints << endl;

    testno++;
    points += lastpoints;
    totpoints += lasttotpoints;

    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    dispatcher();
}

int main()
{
    // Set signal handlers
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);

    cout << "Starting Tests" << endl;

    testno = 0;
    points = 0;
    totpoints = 0;
    dispatcher();
    
}