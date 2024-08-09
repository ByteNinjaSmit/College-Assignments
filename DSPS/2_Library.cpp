// Assignment 2nd Of DSPS Lab
// Author: [Smitraj Dinkar Bankar]
// Problem Defination: Creating Library -> Book Object Perform Operations
// Date:  2024-09-15 [yyyy-mm-DD]
// PRN : UCS23M1009

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Book
{
private:
    int cost;
    string Tt, Author;

public:
    void accept()
    {
        cout << "Enter Title, Author and Cost ";
        cin >> Tt >> Author >> cost;
        cout << "Book Added Successfully." << endl;
    }
    void display()
    {
        //  Title      Author     Cost
        cout << Tt << "\t" << Author << "\t" << cost << endl;
    }
    int returnCost()
    {
        return this->cost;
    }
    string returnTitle()
    {
        return this->Tt;
    }
    string returnAuthor()
    {
        return this->Author;
    }
};

vector<Book> B;

// Display Function To Ascending using Selection Sort
void displayAscending()
{
    // Book temp;
    int n = B.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j =i+1; j < n; j++)
        {
            if (B[i].returnCost() > B[j].returnCost())
            {
                swap(B[i], B[j]);
            }
        }
    }
    cout << "Title \tAuthor\tCost" << endl;
    for (int i = 0; i < n; i++)
    {
        B[i].display();
    }
}

void displayDescending()
{
    int n = B.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (B[i].returnCost() < B[j].returnCost())
            {
                swap(B[i], B[j]);
            }
        }
    }
    cout << "Title \tAuthor\tCost" << endl;
    for (int i = 0; i < n; i++)
    {
        B[i].display();
    }
}

// Count Above Cost 500
void count()
{
    int count = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i].returnCost() > 500)
        {
            count++;
        }
    }
    cout << "Number of books above 500 cost: " << count << endl;
}

// Display Below The 500 Books
void displayBelow500()
{
    int count = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i].returnCost() <= 500)
        {
            count++;
            B[i].display();
        }
    }
    if (count == 0)
    {
        cout << "No books below 500 cost found." << endl;
    }
}
// Remove Duplicate using Temporary Object
void removeDuplicateTemp()
{
    if (B.empty())
        return; // Check if vector B is empty

    vector<Book> temp;
    temp.push_back(B[0]); // Initialize temp with the first element of B
    for (int i = 1; i < B.size(); i++)
    {
        bool isDuplicate = false;
        
        for (int j = 0; j < temp.size(); j++)
        {
            if ((B[i].returnTitle() == temp[j].returnTitle()) && (B[i].returnAuthor() == temp[j].returnAuthor()))
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            temp.push_back(B[i]);
        }
    }
    int duplicates = B.size() - temp.size();
    B = temp; // Replace B with temp

    cout << "Total number of books after removing duplicates: " << duplicates << endl;
    cout << "Duplicate books removed successfully." << endl;
}

// Remove Duplicate Direct
void removeDuplicateDirect()
{
    if (B.empty()) return; // Check if vector B is empty

    // Sort vector B by title and author
    sort(B.begin(), B.end(), [](Book &a, Book &b) {
        if (a.returnTitle() == b.returnTitle()) {
            return a.returnAuthor() < b.returnAuthor();
        }
        return a.returnTitle() < b.returnTitle();
    });

    // After sorting, remove duplicates
    int j = 1;
    for (int i = 1; i < B.size(); i++)
    {
        if (B[i].returnTitle() != B[i - 1].returnTitle() || B[i].returnAuthor() != B[i - 1].returnAuthor())
        {
            B[j++] = B[i];
        }
    }
    int duplicates = B.size() - j;
    B.resize(j); // Resize the vector to remove duplicates
    
    cout << "Total number of books after removing duplicates: " << duplicates << endl;
    cout << "Duplicate books removed successfully." << endl;
}


int main()
{
    Book b;

    int ch = 0;
    while (ch != 9)
    {
        // Accept, Display, Count Above500cost, Ascending, Descending, Display Below 500 Cost, Delete Duplicate Using Temp, Delete Duplicate Direct
        cout << "\nChoose from below options:\n";
        cout << "1. Add Book\n2. Display All Books\n3. Count Books Above 500 Cost\n4. Display Books Ascending\n5. Display Books Descending\n6. Display Books Below 500 Cost\n7. Delete Duplicate Using Temp\n8. Delete Duplicate Direct\n9. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.accept();
            B.push_back(b);
            break;
        case 2:
            cout << "\nTitle \tAuthor\tCost" << endl;
            for (int i = 0; i < B.size(); i++)
            {
                B[i].display();
            }
            break;
        case 3:
            count();
            break;
        case 4:
            displayAscending();
            break;
        case 5:
            displayDescending();
            break;
        case 6:
            displayBelow500();
            break;
        case 7:
            removeDuplicateTemp();
            break;
        case 8:
            removeDuplicateDirect();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}