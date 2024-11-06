/*
Library Management System
==========================
Accept Book Title, Author Name, Publisher & Price of the Book.
Add the book to the library.
Display all the books in the library.

Name: Smitraj Dinkar Bankar
PRN: UCS23M1009
Date: 24/10/2024
Assignment : Singly Linked-List Using C++
*/

#include <iostream>
#include <string>
using namespace std;

class LMS
{
    string title, author, publisher;
    int price;
    LMS *next; // Pointer to the next node in the list

public:
    // Function to accept details of a book and add to the linked list
    void accept();
    // Function to display the list of books
    void display();

    // Function to Search the Record of Book.
    void search();

    // Function to Delete the Record of Book.
    void deleteRecord();
    void firstDelete();
    void lastDelete();
};

// Global head pointer to point to the start of the list
LMS *head = NULL;

// Accept Function Defination
void LMS::accept()
{
    LMS *nnode = new LMS; // Create a new node

    cout << "Enter title: ";
    cin >> nnode->title;
    cout << "Enter author: ";
    cin >> nnode->author;
    cout << "Enter publisher: ";
    cin >> nnode->publisher;
    cout << "Enter price: ";
    cin >> nnode->price;
    nnode->next = NULL; // Set next pointer of the new node to NULL

    // Check if the list is empty, if so, set the new node as the head
    if (head == NULL)
    {
        head = nnode;
    }
    else
    {
        // Traverse to the end of the list and add the new node
        LMS *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nnode; // Add new node at the end of the list
    }
}
// Display Function Defination
void LMS::display()
{
    if (head == NULL)
    {
        cout << "No books available." << endl;
        return;
    }

    LMS *temp = head;
    while (temp != NULL) // Traverse through the list
    {
        cout << "\nTitle: " << temp->title << endl;
        cout << "Author: " << temp->author << endl;
        cout << "Publisher: " << temp->publisher << endl;
        cout << "Price: " << temp->price << endl;
        cout << "--------------------------" << endl;
        temp = temp->next; // Move to the next node
    }
}

// Search Function Defination
void LMS::search()
{
    if (head == NULL)
    {
        cout << "No books available." << endl;
        return;
    }
    else
    {
        string search;
        cout << "Enter the title of the book you want to search: ";
        cin >> search;
        int flag;
        LMS *temp = head;
        while (temp != NULL) // Traverse through the list
        {
            if (temp->title == search)
            {
                flag = 1;
                break;
            }
            temp = temp->next; // Move to the next node
        }

        if (flag != 0)
        {
            cout << "\nTitle: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Publisher: " << temp->publisher << endl;
            cout << "Price: " << temp->price << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "\nBook not found." << endl;
        }
    }
}
// Deletion At Position Function Defination
void LMS::deleteRecord()
{
    if (head == NULL)
    {
        cout << "No books available." << endl;
        return;
    }

    string search;
    cout << "Enter the title of the book you want to delete: ";
    cin >> search;

    LMS *temp = head;
    LMS *prev = NULL;
    bool found = false;

    // Traverse the list to find the book
    while (temp != NULL)
    {
        if (temp->title == search) // Assuming `title` is the attribute holding the book's title
        {
            found = true;
            // If the book to delete is the head
            if (temp == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Book deleted successfully." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}

// Deleting First Function Defination
void LMS::firstDelete()
{
    if (head == NULL)
    {
        cout << "No books available." << endl;
        return;
    }
    else
    {
        LMS *temp = head;
        head = temp->next;
        delete head;
        cout << "Book deleted successfully." << endl;
        return;
    }
}

void LMS::lastDelete()
{
    if (head == NULL)
    {
        cout << "No books available." << endl;
        return;
    }
    else
    {
        LMS *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Book deleted successfully." << endl;
        return;
    }
}

int main()
{
    LMS L; // Create an instance of the LMS class
    int choice;

    do
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            L.accept(); // Add a new book
            break;
        case 2:
            L.display(); // Display all books
            break;
        case 3:
            L.search();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
