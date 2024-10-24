#include <iostream>
#include <string>

using namespace std;

int first = 0; // To check if the first order has been placed
int f = -1, r = -1;
const int price = 100;
const int max_size = 10;
const int pizza_time = 10;

// Circular Queue for managing pizza orders
class Pizza
{
private:
    string name, add;
    int quantity;

public:
    void acceptOrder();
    void servOrder();
    void displayOrders();
    void peakOrder();
    void cancelOrder();
    int getQty()
    {
        return quantity;
    }
} P[max_size];

int getQueueCount()
{
    if (f == -1 && r == -1)
    {
        return 0; // No orders
    }
    else if (f <= r)
    {
        return r - f + 1;
    }
    else
    {
        return max_size - f + r + 1;
    }
}

int getTime()
{
    int TotalQty = 0;
    int i = f;
    while (i != r)
    {
        TotalQty += P[i].getQty();
        i = (i + 1) % max_size;
    }
    TotalQty += P[r].getQty();
    return TotalQty * pizza_time;
}

void Pizza::acceptOrder()
{
    // Check if the queue is full
    if ((f == 0 && r == max_size - 1) || (f == r + 1))
    {
        cout << "Pizza Shop Order Full! Visit Again Later." << endl;
        return;
    }

    // Accept order details
    string name, address;
    int quantity;

    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Your Address: ";
    cin >> address;
    cout << "Enter Quantity: ";
    cin >> quantity;

    if (quantity < 0)
    {
        throw runtime_error("Enter Greater than 0. "); 
    }
    
    // First order gets a discount
    if (f == -1 && r == -1)
    {

        f = 0;
        r = 0;
        P[r].name = name;
        P[r].add = address;
        P[r].quantity = quantity;

        if (first == 0)
        {
            first = 1;
            cout << "Congratulations! You're the first customer and get a Rs. 20 discount per pizza!" << endl;
            cout << "Your bill: Rs. " << (P[r].quantity * price) - 20 << endl;
        }
        else
        {
            cout << "Your bill: Rs. " << (P[r].quantity * price) << endl;
        }
    }
    else
    {
        r = (r + 1) % max_size;
        P[r].name = name;
        P[r].add = address;
        P[r].quantity = quantity;
        cout << "Your bill: Rs. " << (P[r].quantity * price) << endl;
    }
    cout << "You Have To Wait: " << getTime() << " Mins." << endl;
    cout << "You are customer number " << getQueueCount() << " in the queue." << endl;
}

void Pizza::servOrder()
{
    if (f == -1 && r == -1)
    {
        cout << "No orders to serve!" << endl;
        return;
    }

    // Serve the current order
    cout << "Serving Order:" << endl;
    cout << "Name: " << P[f].name << endl;
    cout << "Address: " << P[f].add << endl;
    cout << "Quantity: " << P[f].quantity << endl;

    // Check if it was the last order
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % max_size;
    }
}

void Pizza::displayOrders()
{
    if (f == -1 && r == -1)
    {
        cout << "No orders!" << endl;
        return;
    }

    cout << "All Orders in the Queue:" << endl;
    int i = f;
    while (i != r)
    {
        cout << "Name: " << P[i].name << ", Address: " << P[i].add << ", Quantity: " << P[i].quantity << endl;
        i = (i + 1) % max_size;
    }
    // Display the last order
    cout << "Name: " << P[r].name << ", Address: " << P[r].add << ", Quantity: " << P[r].quantity << endl;

    cout << "Total Orders in Queue: " << getQueueCount() << endl;
}

void Pizza::peakOrder()
{
    if (f == -1 && r == -1)
    {
        cout << "No orders!" << endl;
    }
    else
    {
        cout << "Next Order in Queue:" << endl;
        cout << "Name: " << P[f].name << ", Address: " << P[f].add << ", Quantity: " << P[f].quantity << endl;
    }
}

void Pizza::cancelOrder()
{
    if (f == -1 && r == -1)
    {
        cout << "No orders to cancel!" << endl;
        return;
    }

    // Show order to cancel
    cout << "Cancelling Order:" << endl;
    cout << "Name: " << P[f].name << ", Address: " << P[f].add << ", Quantity: " << P[f].quantity << endl;

    // Refund 50%
    int refundAmount = (P[f].quantity * price) / 2;
    cout << "You will receive a 50% refund of Rs. " << refundAmount << endl;

    // Remove the order
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % max_size;
    }
}

int main()
{
    int choice = 0;
    int temp1;
    while (choice != 6)
    {
        cout << "\n1. Accept Order\n2. Serve Order\n3. Display All Orders\n4. Current Order\n5. Cancel Order\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            try
            {

                if (f == -1 && r == -1)
                {
                    P[0].acceptOrder();
                }
                else
                {
                    cout << "You Have To Wait: " << getTime() << " Mins." << endl;
                    cout << "You are customer number " << getQueueCount() + 1 << " in the queue." << endl;
                    cout << "Do You want to Still the Order ? (Yes/No) : ";
                    cin >> temp1;
                    if (temp1 == 1)
                    {
                        P[0].acceptOrder();
                    }
                    else
                    {
                        cout << "Order Cancelled" << endl;
                    }
                }
            }
            catch (runtime_error &e)
            {
               cout << e.what() << endl;
            }
            break;
        case 2:
            P[0].servOrder();
            break;
        case 3:
            P[0].displayOrders();
            break;
        case 4:
            P[0].peakOrder();
            break;
        case 5:
            P[0].cancelOrder();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
