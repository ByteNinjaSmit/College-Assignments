#include <iostream>
#include <string>

using namespace std;

const int max_size = 5;
int f = -1;
int r = -1;
int Deque[max_size];

void enqFront()
{

    if ((f == 0 && r == max_size - 1) || (f == r + 1) || (f == 0))
    {
        cout << "Queue Is Full" << endl;
    }
    else if (f == -1)
    {
        f = max_size - 1;
        // r = 0;
        cout << "Enter Element: ";
        cin >> Deque[f];
    }
    else
    {
        f--;
        cout << "Enter Element: ";
        cin >> Deque[f];
    }
}

void enqRear()
{
    if ((f == 0 && r == max_size - 1) || (f == r + 1) || (r == max_size - 1))
    {
        cout << "Queue Is Full" << endl;
    }
    else if (r == -1)
    {
        // f = max_size - 1;
        r = 0;
        cout << "Enter Element: ";
        cin >> Deque[r];
    }
    else
    {
        r++;
        cout << "Enter Element: ";
        cin >> Deque[r];
    }
}

void dequeFront()
{
    if (f == -1 && r == -1)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    if (f == r)
    {
        cout << "Dequeue Element: " << Deque[f] << endl;
        f = -1;
        r = -1;
    }
    else
    {
        cout << "Dequeue Element: " << Deque[f] << endl;
        f = (f + 1) % max_size;
    }
}

void dequeRear()
{
    if (f == -1 && r == -1)
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    if (f == r)
    {
        cout << "Dequeue Element: " << Deque[r] << endl;
        f = -1;
        r = -1;
    }
    else
    {
        cout << "Dequeue Element: " << Deque[r] << endl;
        r = (r - 1 + max_size) % max_size;
    }
}

void display() {
    // Check if the queue is empty
    if (f == -1 && r == -1) {
        cout << "No orders!" << endl;
        return;
    }

    cout << "All Orders in the Queue:" << endl;
    
    // Case 1: If the front is less than or equal to the rear
    if (f <= r) {
        for (int i = f; i <= r; i++) {
            cout << Deque[i] << "\t";
        }
    }
    // Case 2: If the front is greater than the rear (wrap-around case)
    else {
        for (int i = f; i < max_size; i++) {
            cout << Deque[i] << "\t";
        }
        for (int i = 0; i <= r; i++) {
            cout << Deque[i] << "\t";
        }
    }

    cout << endl;
}


int main()
{
    int ch = 0;
    while (ch != 6)
    {
        cout << "\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit" << endl;
        cout << "Enter Correct Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqFront();
            break;
        case 2:
            enqRear();
            break;
        case 3:
            dequeFront();
            break;
        case 4:
            dequeRear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Exiting........" << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}

// Other functions remain unchanged...

// Other parts of main and functions remain unchanged...
