#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    int id;
    string name, ds;
    virtual void accept() = 0; // Pure virtual function for accepting details
    virtual void display() = 0; // Pure virtual function for displaying details
};

class Doctor : public Person
{
    int sal; // Salary
public:
    // Accept details for the Doctor
    void accept() {
        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Doctor Name: ";
        cin >> name;
        cout << "Enter Doctor Designation: ";
        cin >> ds;
        cout << "Enter Doctor Salary: ";
        cin >> sal;
    }

    // Display Doctor details
    void display() {
        cout << "\nDoctor Details:\n";
        cout << id << "\t" << name << "\t" << ds << "\t" << sal << endl;
    }
};

class AStaff : public Person
{
    int sal; // Salary
public:
    // Accept details for the Administrative Staff
    void accept() {
        cout << "Enter Staff ID: ";
        cin >> id;
        cout << "Enter Staff Name: ";
        cin >> name;
        cout << "Enter Staff Designation: ";
        cin >> ds;
        cout << "Enter Staff Salary: ";
        cin >> sal;
    }

    // Display Administrative Staff details
    void display() {
        cout << id << "\t" << name << "\t" << ds << "\t" << sal << endl;
    }
};

class Nurse : public Person
{
    int sal; // Salary amount
public:
    // Accept details for the Nurse
    void accept() {
        cout << "Enter Nurse ID: ";
        cin >> id;
        cout << "Enter Nurse Name: ";
        cin >> name;
        cout << "Enter Nurse Designation: ";
        cin >> ds;
        cout << "Enter Nurse Salary: ";
        cin >> sal;
    }

    // Display Nurse details
    void display() {
        cout << id << "\t" << name << "\t" << ds << "\t" << sal << endl;
    }
};

int main()
{
    Doctor d;
    vector<AStaff> staffList;  // Vector to store multiple AStaff objects
    vector<Nurse> nurseList;   // Vector to store multiple Nurse objects
    int choice;

    // Accept details for Doctor (only once)
    cout << "Enter Doctor Information:\n";
    d.accept();

    // Loop to accept details for AStaff and Nurse multiple times based on user choice
    do {
        cout << "\n1. Add Administrative Staff\n2. Add Nurse\n3. Display All\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Accept details for AStaff
                AStaff a;
                cout << "\nEnter Administrative Staff Information:\n";
                a.accept();
                staffList.push_back(a); // Add AStaff object to the vector
                break;
            }

            case 2: {
                // Accept details for Nurse
                Nurse n;
                cout << "\nEnter Nurse Information:\n";
                n.accept();
                nurseList.push_back(n); // Add Nurse object to the vector
                break;
            }

            case 3: {
                // Display Doctor details
                cout << "\n----- Doctor Details -----\n";
                d.display();

                // Display all AStaff details
                cout << "\n----- Administrative Staff Details -----\n";
                if (staffList.empty()) {
                    cout << "No Administrative Staff records found.\n";
                } else {
                    for (size_t i = 0; i < staffList.size(); ++i) {
                        staffList[i].display();
                    }
                }

                // Display all Nurse details
                cout << "\n----- Nurse Details -----\n";
                if (nurseList.empty()) {
                    cout << "No Nurse records found.\n";
                } else {
                    for (size_t i = 0; i < nurseList.size(); ++i) {
                        nurseList[i].display();
                    }
                }
                break;
            }

            case 4:
                // Exit case
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

    } while (choice != 4); // Continue until the user selects 'Exit'

    return 0;
}
