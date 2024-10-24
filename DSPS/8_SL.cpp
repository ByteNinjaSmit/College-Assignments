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
} ;

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

int main()
{
    LMS L; // Create an instance of the LMS class
    int choice;

    do
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Exit\n";
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
