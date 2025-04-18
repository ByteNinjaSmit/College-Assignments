#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Singly Linked-List
class LL
{
public:
    int data;
    // Next Node
    LL *next;
    LL *prev;

    // paramaterized default constructor
    LL(int data = 0)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    void accept();
    void display();
    void search();
    // void displayAcc();
    void displayDec();
};

LL *head = NULL;
LL *tail = NULL;
// accept function
void LL::accept()
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    // Create a new node
    LL *new_node = new LL(data);
    new_node->prev = NULL;
    new_node->next = NULL;
    // Check if the list is empty, if so, set the new node as the head
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        // Traverse to the end of the list and add the new node
        LL *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node; // Add new node at the end of the list
    }
}

// Display Function
void LL::display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    LL *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// Search Function
void LL::search()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    int data;
    int flag = 0;
    cout << "Enter the data to search: ";
    cin >> data;
    LL *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            flag = 1;
            // cout<<"Data found"<<endl;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout << "Data not found" << endl;
    }
    else
    {
        cout << "Data found" << endl;
        cout << temp->data << endl;
    }
}

void LL::displayDec(){
    if (head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    cout<<"Hiiiiiii"<<endl;
}

int main()
{
    LL L;
    int ch;
    while (ch != 4)
    {
        //   cout << "\nLibrary Management System\n";
        cout << "1. Add \n";
        cout << "2. Display \n";
        cout << "3. Search \n";
        cout << "4. Display Descending \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            L.accept();
            break;
        case 2:
            L.display();
            break;
        case 3:
            L.search();
            break;
        case 4:
            L.displayDec();
            break;
        case 5:
            cout << "exit";
            break;
        default:
            break;
        }
    }

    return 0;
}