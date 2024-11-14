/*

a charity management system need to manage the ijnformation about donors , 
donation and other releavant information sytem need to mainttain information about  
each donor system shuold able to add new donor remove the donor , 
update the information of the donor search the specific donor also it should display all the 
information of all the donor present in the database . 
use the concept of linklist to implement above system 

*/

#include <iostream>
#include <string>
using namespace std;

class Donor
{
    string name;
    string donation_name;
    int id;
    Donor *next;
    Donor *prev;

public:
    Donor() : next(NULL), prev(NULL) {}

    void accept();
    void display();
    static void addDonor();
    static void removeDonor(int id);
    static void updateDonor(int id);
    static void searchDonor(int id);
    static void displayAll();
    static void count();

    // friend class DonorList;
};

Donor *head = NULL;

// Method to accept new donor data and add to the list
void Donor::accept()
{
    Donor *newnode = new Donor;
    cout << "Enter name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newnode->name);
    cout << "Enter donation thing name: ";
    getline(cin, newnode->donation_name);
    cout << "Enter id: ";
    cin >> newnode->id;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Donor *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    cout << "Donor added successfully.\n";
}

// Display information of a single donor
void Donor::display()
{
    cout << "Name: " << name << ", Donation Thing Name: " << donation_name << ", ID: " << id << endl;
}

// Add a new donor by calling the accept method
void Donor::addDonor()
{
    Donor *newDonor = new Donor;
    newDonor->accept();
}

// Remove a donor by ID
void Donor::removeDonor(int id)
{
    if (head == NULL)
    {
        cout << "No donors available to remove.\n";
        return;
    }
    Donor *temp = head;
    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Donor with ID " << id << " not found.\n";
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next; // Removing the head node
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Donor removed successfully.\n";
}

// Update a donor's information by ID
void Donor::updateDonor(int id)
{
    if (head == NULL)
    {
        cout << "No donors available to update.\n";
        return;
    }
    Donor *temp = head;
    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Donor with ID " << id << " not found.\n";
        return;
    }

    cout << "Enter new name: ";
    cin.ignore();
    getline(cin, temp->name);
    cout << "Enter Donation Thing name: ";
    getline(cin, temp->donation_name);
    cout << "Enter new ID: ";
    cin >> temp->id;
    cout << "Donor updated successfully.\n";
}

// Search for a donor by ID
void Donor::searchDonor(int id)
{
    if (head == NULL)
    {
        cout << "No donors available to search.\n";
        return;
    }
    Donor *temp = head;
    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Donor with ID " << id << " not found.\n";
    }
    else
    {
        temp->display();
    }
}

// Display all donors
void Donor::displayAll()
{
    if (head == NULL)
    {
        cout << "No donors to display.\n";
        return;
    }
    Donor *temp = head;
    while (temp != NULL)
    {
        temp->display();
        temp = temp->next;
    }
}

// Display The No Of Records Of Donors
void Donor::count()
{
    int count = 0;
    Donor *temp = head;
    // count The Records
    while (temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    cout << "Total number of donors: " << count << endl;
}

int main()
{
    int choice, id;
    do
    {
        cout << "\nCharity Management System\n";
        cout << "1. Add Donor\n";
        cout << "2. Remove Donor\n";
        cout << "3. Update Donor\n";
        cout << "4. Search Donor\n";
        cout << "5. Display All Donors\n";
        cout << "6. Count The Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Donor::addDonor();
            break;
        case 2:
            cout << "Enter donor ID to remove: ";
            cin >> id;
            Donor::removeDonor(id);
            break;
        case 3:
            cout << "Enter donor ID to update: ";
            cin >> id;
            Donor::updateDonor(id);
            break;
        case 4:
            cout << "Enter donor ID to search: ";
            cin >> id;
            Donor::searchDonor(id);
            break;
        case 5:
            Donor::displayAll();
            break;
        case 6:
            Donor::count();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
