/*
Assignment 7
A student record system is software application used to manage student records including student info, 10th, 12th
result. Hash table can be used  as a data structure to efficiently store or retrieve student records

algo: linear probing with chain hashing
*/

#include <iostream>
using namespace std;

int key[20], n;
int chain[20]; // for chain hashing

class studentRecords
{
    int ID;
    string Name;

public:
    void Table();
    void accept();
    void display();
    void search();
    void modify();
    void deleteStudent();
} h[20]; // increased to 20 for more capacity

void studentRecords::Table()
{
    // Initialize chain and hash table
    for (int i = 0; i < 20; i++)
    {
        chain[i] = -1;
        h[i].ID = -1;
    }

    cout << "Enter No. of records you want to store: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter ID " << i + 1 << ": ";
        cin >> key[i];
    }
}
void studentRecords::accept()
{
    for (int i = 0; i < n; i++)
    {
        int id = key[i];
        int loc = id % 10; // hash function base index
        int newLoc = loc;

        if (h[loc].ID == -1)
        {
            // No collision
            cout << "Enter Name for ID " << id << ": ";
            cin >> h[loc].Name;
            h[loc].ID = id;
            cout << "Record added at location " << loc << "." << endl;
        }
        else
        {
            // Collision occurred
            cout << "\nCollision occurred at location " << loc << " for ID " << id << "!!!" << endl;

            // Linear probing to find next empty slot
            do
            {
                newLoc = (newLoc + 1) % 20;
            } while (h[newLoc].ID != -1);

            // Add data to new location
            cout << "Enter Name for ID " << id << ": ";
            cin >> h[newLoc].Name;
            h[newLoc].ID = id;
            cout << "Record added at location " << newLoc << "." << endl;

            // Now find previous record in the chain
            int temp = loc;
            while (chain[temp] != -1)
            {
                temp = chain[temp];
            }

            // Link last chain element to the new location
            chain[temp] = newLoc;
        }
    }
}


void studentRecords::display()
{
    cout << "\nStudent Records: \n";
    cout << "Loc\tID\tName\tChain" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << i << "\t" << h[i].ID << "\t" << h[i].Name << "\t" << chain[i] << endl;
    }
}

void studentRecords::search()
{
    int id, ch;
    bool found;
    do
    {
        found = false;
        cout << "\nEnter student ID to search: ";
        cin >> id;
        int loc = id % 10;

        // Search in chain
        while (loc != -1)
        {
            if (h[loc].ID == id)
            {
                cout << "Record found at location " << loc << ": ID = " << h[loc].ID << ", Name = " << h[loc].Name << endl;
                found = true;
                break;
            }
            loc = chain[loc];
        }

        if (!found)
            cout << "Record not found!" << endl;

        cout << "\nDo you want to search another record? (Yes-1/No-0): ";
        cin >> ch;
    } while (ch != 0);
}

void studentRecords::modify()
{
    int id, ch;
    bool found;
    do
    {
        found = false;
        cout << "\nEnter student ID to modify: ";
        cin >> id;
        int loc = id % 10;

        // Traverse the chain
        while (loc != -1)
        {
            if (h[loc].ID == id)
            {
                cout << "Record found at location " << loc << ": ID = " << h[loc].ID << ", Name = " << h[loc].Name << endl;
                cout << "Enter new Name: ";
                cin >> h[loc].Name;
                cout << "Record modified successfully!" << endl;
                found = true;
                break;
            }
            loc = chain[loc];
        }

        if (!found)
            cout << "Record not found!" << endl;

        cout << "\nDo you want to modify another record? (Yes-1/No-0): ";
        cin >> ch;
    } while (ch != 0);
}

// Delete Student Record Logic
void studentRecords::deleteStudent()
{
    int id, ch;
    bool found;
    do
    {
        found = false;
        cout << "\nEnter student ID to delete: ";
        cin >> id;
        for (int i = 0; i < 10; i++)
        {
            if (h[i].ID == id)
            {
                found = true;
                cout << "Record found at location " << i << ": ID = " << h[i].ID << ", Name = " << h[i].Name << endl;
                h[i].ID = -1;        // Mark ID as deleted
                h[i].Name = "";      // Clear name
                cout << "Record deleted successfully!" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Record not found!" << endl;
        }

        cout << "\nDo you want to delete another record? (Yes - 1 / No - 0): ";
        cin >> ch;
    } while (ch != 0);
}

int main()
{
    int choice;
    studentRecords m;
    cout << "\n\tStudent Record System\n";
    do
    {
        cout << "\n1. Create Student Records\n2. Display Student Records\n3. Search Student Records\n4. Modify Student Records\n5. Delete Student Record\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.Table();
            m.accept();
            break;
        case 2:
            m.display();
            break;
        case 3:
            m.search();
            break;
        case 4:
            m.modify();
            break;
        case 5:{
            m.deleteStudent();
            break;
        }
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
        cout << "\nDo you want to continue? (Yes-1/No-0): ";
        cin >> choice;
    } while (choice != 0);
    return 0;
}
