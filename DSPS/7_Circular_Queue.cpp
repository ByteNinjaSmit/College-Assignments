#include <iostream>
using namespace std;

const int max_size = 10;
int front = -1;
int rear = -1;
int queue[max_size];
// Circular Queue
void enqueue(int x)
{
    if ((rear == max_size - 1 && front == 0) || (rear == front - 1))
    {
        cout << "Queue is Full" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % max_size;
        queue[rear] = x;
    }
}

// Dequeue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front == rear)
    {
        cout << "Dequeue: " << queue[front] << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "Dequeue: " << queue[front] << endl;
        front = (front + 1) % max_size;
    }
}

// Display
void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (front < rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
    else
    {         
        for (int i = front; i < max_size; i++)
        {
            cout << queue[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    int ch = 0;
    int t;
    while (ch != 3)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Number For Enqueue: ";
            cin >> t;
            enqueue(t);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting...." << endl;
            break;
        }
    }
    return 0;
}