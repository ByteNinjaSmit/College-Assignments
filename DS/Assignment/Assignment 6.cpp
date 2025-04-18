/* Assignment 6
Def - A medical record system is a software application used to manage medical records including patient information, medical history, and treatment plan.
Hash table can be used as a data structure to efficiently store and retrieve medical records.
*/

#include <iostream>
using namespace std;

int key[20], n;

class medicalRecords
{
    int ID;
    string Name;
public:
    void Table();
    void accept();
    void display();
    void search();
    void modify();
} h[50];

void medicalRecords::Table()
{
    cout << "Enter No. of Records you want to store: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter ID " << i + 1 << " : ";
        cin >> key[i];
    }
    for (int i = 0; i < 10; i++)
    {
        h[i].ID = -1; // initializing hash table
    }
}

void medicalRecords::accept()
{
    int loc;
    for (int i = 0; i < n; i++)
    {
        loc = key[i] % 10;
        if (h[loc].ID == -1)
        {
            h[loc].ID = key[i];
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            cout << "Record Added at location " << loc << "." << endl;
        }
        else
        {
            cout << "Collision Occurred at location " << loc << "!!!" << endl;
            loc = (loc + 1) % 10;
            while (h[loc].ID != -1)
            {
                loc = (loc + 1) % 10;
            }
            h[loc].ID = key[i];
            cout << "Enter Name for ID " << key[i] << " : ";
            cin >> h[loc].Name;
            cout << "Record Added at location " << loc << "." << endl;
        }
    }
}

void medicalRecords::display()
{
    cout << "\nMedical Records: \n";
    cout << "Location\tID\tName" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (h[i].ID != -1)
            cout << i << "\t\t" << h[i].ID << "\t" << h[i].Name << endl;
        else
            cout << i << "\t\t" << "--\t--" << endl;
    }
}

void medicalRecords::search()
{
    int id, loc, count = 0;
    cout << "Enter ID to Search: ";
    cin >> id;
    loc = id % 10;

    while (h[loc].ID != id && count < 10)
    {
        loc = (loc + 1) % 10;
        count++;
    }

    if (h[loc].ID == id)
        cout << "Record Found at location " << loc << ": Name = " << h[loc].Name << endl;
    else
        cout << "Record Not Found!" << endl;
}

void medicalRecords::modify()
{
    int id, loc, count = 0;
    cout << "Enter ID to Modify: ";
    cin >> id;
    loc = id % 10;

    while (h[loc].ID != id && count < 10)
    {
        loc = (loc + 1) % 10;
        count++;
    }

    if (h[loc].ID == id)
    {
        cout << "Current Name: " << h[loc].Name << endl;
        cout << "Enter New Name: ";
        cin >> h[loc].Name;
        cout << "Record Updated!" << endl;
    }
    else
    {
        cout << "Record Not Found!" << endl;
    }
}

int main()
{
    medicalRecords m;
    m.Table();
    m.accept();
    m.display();

    int choice;
    do
    {
        cout << "\nMenu:\n1. Search\n2. Modify\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            m.search();
            break;
        case 2:
            m.modify();
            break;
        case 3:
            m.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
