#include <iostream>
using namespace std;

const int max_size = 10;

class Queue
{
    int ele;

public:
    static int f, r;

    void display()
    {
        cout << ele << "\t";
    }
    // Friend Functions
    friend void enqueue(Queue &Q);
    friend void peek(Queue Q[]);
    friend void dequeue(Queue Q[]);

    void setEle(int n)
    {
        ele = n;
    }

    int getEle()
    {
        return ele;
    }

    static int getF()
    {
        return f;
    }

    static int getR()
    {
        return r;
    }
};

int Queue::f = -1;
int Queue::r = -1;

void peek(Queue Q[])
{
    if (Queue::f == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element: " << Q[Queue::f].getEle() << "\n";
}

void enqueue(Queue Q[])
{
    if (Queue::r == max_size - 1)
    {
        cout << "Queue is full.\n";
        return;
    }
    int n;
    cout << "Enter Element: ";
    cin >> n;
    if (Queue::r == -1)
    {
        Queue::r = 0;
        Queue::f = 0;
    }
    else
    {
        Queue::r++;
    }
    Q[Queue::r].setEle(n);
}

void dequeue(Queue Q[])
{
    if (Queue::r == -1 || Queue::f == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Dequeued element: " << Q[Queue::f].getEle() << "\n";

    if (Queue::f == Queue::r)
    { // Only one element was in the queue
        Queue::f = -1;
        Queue::r = -1;
    }
    else
    {
        Queue::f++;
    }
}

int main()
{
    Queue Q[max_size]; // Declaring Array Of Objects
    int ch = 0;

    while (ch != 5)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            enqueue(Q);
            break;
        case 2:
            dequeue(Q);
            break;
        case 3:
            if (Queue::f == -1)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                for (int i = Queue::f; i <= Queue::r; i++)
                {
                    Q[i].display();
                }
                cout << "\n";
            }
            break;
        case 4:
            peek(Q);
            break;
        case 5:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Enter a correct choice." << endl;
        }
    }
    return 0;
}
