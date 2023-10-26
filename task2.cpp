#include <cstdio>
#include <signal.h>
#include <iostream>
#include <string>
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

int testno;
int totpoints;
int lastpoints;
int lasttotpoints;
int points;

void test_stack()
{
    lasttotpoints = 0;

    Stack<int> s;
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        s.Push(i);
    }
    cout << ".";

    Stack<int> s2(s);
    cout << ".";

    for (int i = 24999; i >= 0; i--)
    {
        int k = s.Peek();
        int k2 = s.Pop();

        if (k != k2 || k2 != i)
            int a = 1/0;
    }
    cout << ".";

    for (int i = 24999; i >= 0; i--)
    {
        int k = s2.Peek();
        int k2 = s2.Pop();

        if (k != k2 || k2 != i)
            int a = 1/0;
    }
    cout << ".";
    lastpoints = 5;
    lasttotpoints += 5;
}

void test_queue()
{
    lasttotpoints = 5;

    Queue<int> q;
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        q.Enqueue(i);
    }
    cout << ".";

    Queue<int> q2(q);
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        int k = q.Peek();
        int k2 = q.Dequeue();

        if (k != k2 || k2 != i)
            int a = 1/0;
    }
    cout << ".";

    for (int i = 0; i < 25000; i++)
    {
        int k = q2.Peek();
        int k2 = q2.Dequeue();

        if (k != k2 || k2 != i)
            int a = 1/0;
    }
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
                    cout << "Testing Stack ";
                    test_stack();
                }
                break;
            case 1:
                {
                    cout << "Testing Queue ";
                    test_queue();
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
