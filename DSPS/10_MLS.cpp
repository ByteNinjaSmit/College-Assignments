#include <iostream>
using namespace std;

class MLS
{
    int TID;          // Music Track Id
    string TName;     // Music Track Name
    string Artist;    // Artist Name
    string Album;     // Album Name
    int Year;         // Release Year
    MLS *next, *prev; // Node for Transversing

public:
    //  Default Constructor
    MLS() : next(NULL), prev(NULL) {}

    // fucntion Operation
    void accept();
    void display();
    static void addMusic();
    static void DisplayAll();
    static void removeMusic(int id);
    static void updateMusic(int id);
    static void searchMusic(int id);
    static void countMusic();
    static void reverseDisplayAll();
};

// Head & Tail
MLS *head = NULL;
MLS *tail = NULL;

void MLS::accept()
{
    MLS *newnode = new MLS;
    cout << "Enter Music Track Id: ";
    cin >> newnode->TID;
    cout << "Enter Music Track Name: ";
    cin >> newnode->TName;
    cout << "Enter Artist Name: ";
    cin >> newnode->Artist;
    cout << "Enter Music Year: ";
    cin >> newnode->Year;
    cout << "Enter Album Name: ";
    cin >> newnode->Album;

    // NUll Initialy
    newnode->next = NULL;
    newnode->prev = NULL;

    // Insert at the end of the list
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        MLS *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        tail = temp;
    }

    cout << "Music Added Successfully" << endl;
}

// Add New Music

void MLS::addMusic()
{
    MLS *newnode = new MLS;
    newnode->accept();
}

// Single  Record Display
void MLS::display()
{
    cout << "Track Id: " << TID << ", Music Name: " << TName << ", Artist: " << Artist << ", Year: " << Year << ", Album Name: " << Album << endl;
}

// Display All Function
void MLS::DisplayAll()
{
    // Checking Empty or Not
    if (head == NULL)
    {
        cout << "No Music Available to Display.\n";
        return;
    }
    MLS *temp = head;
    // Displaying From Starting
    while (temp != NULL)
    {
        temp->display();
        temp = temp->next;
    }
}

// Remove Music
void MLS::removeMusic(int id)
{
    if (head == NULL)
    {
        cout << "No Music Available to Remove.\n";
        return;
    }
    MLS *temp = head;
    while (temp != NULL && temp->TID != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Music with ID " << id << " not found.\n";
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next; // Removing head Node
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "Music Removed Successfully.\n";
}

//  Update Music
void MLS::updateMusic(int id)
{
    if (head == NULL)
    {
        cout << "No Music Available to Update.\n";
        return;
    }
    MLS *temp = head;
    while (temp != NULL && temp->TID != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Music with ID " << id << " not found.\n";
        return;
    }
    cout << "Enter Music Track Id: ";
    cin >> temp->TID;
    cout << "Enter Music Track Name: ";
    cin >> temp->TName;
    cout << "Enter Artist Name: ";
    cin >> temp->Artist;
    cout << "Enter Music Year: ";
    cin >> temp->Year;
    cout << "Enter Album Name: ";
    cin >> temp->Album;

    // Done
    cout << "Music updated Successfully.\n";
}

// Search Music
void MLS::searchMusic(int id)
{
    if (head == NULL)
    {
        cout << "No Music Available to Search.\n";
        return;
    }
    MLS *temp = head;
    while (temp != NULL && temp->TID != id)
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

// Count Music Record
void MLS::countMusic()
{
    int count = 0;
    MLS *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Total Number of Music Records: " << count << endl;
}

// Reverse Display
void MLS::reverseDisplayAll()
{
    // Checking Empty or Not
    if (head == NULL)
    {
        cout << "No Music Available to Display.\n";
        return;
    }
    MLS *temp = tail;
    // Displaying From Starting
    while (temp != NULL)
    {
        temp->display();
        temp = temp->prev;
    }
}
int main()
{
    int ch, id;
    while (ch != 7)
    {
        cout << "\nMusic Library Management System\n";
        cout << "1. Add Music\n";
        cout << "2. Remove Music\n";
        cout << "3. Update Music\n";
        cout << "4. Display All Musics\n";
        cout << "5. Search Donor\n";
        cout << "6. Count The Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            MLS::addMusic();
            break;
        case 2:
            cout << "Enter Music ID to remove: ";
            cin >> id;
            MLS::removeMusic(id);
            break;
        case 3:
            cout << "Enter Music ID to update: ";
            cin >> id;
            MLS::updateMusic(id);
            break;
        case 4:
            MLS::DisplayAll();
            break;
        case 5:
            cout << "Enter donor ID to search: ";
            cin >> id;
            MLS::searchMusic(id);
            break;
        case 6:
            MLS::countMusic();
            break;
        case 7:
            cout << "Exiting.." << endl;
            break;
        default:
            cout << "Enter Correct Choice" << endl;
            break;
        }
    }
    return 0;
}