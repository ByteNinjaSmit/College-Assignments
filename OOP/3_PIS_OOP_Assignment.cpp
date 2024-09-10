#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class PersonnelInfo {
private:
    string name;
    string dob;  // Date of Birth
    string bloodGroup;
    float height;
    float weight;
    string insurancePolicyNumber;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

    // Static member to count total personnel records
    static int recordCount;

public:
    // Default Constructor
    PersonnelInfo() {
        name = "Unknown";
        dob = "Unknown";
        bloodGroup = "Unknown";
        height = 0.0;
        weight = 0.0;
        insurancePolicyNumber = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNumber = "Unknown";
        recordCount++;
    }

    // Parameterized Constructor
    PersonnelInfo(string n, string d, string bg, float h, float w, string ipn, string ca, string tn, string dl) {
        name = n;
        dob = d;
        bloodGroup = bg;
        height = h;
        weight = w;
        insurancePolicyNumber = ipn;
        contactAddress = ca;
        telephoneNumber = tn;
        drivingLicenseNumber = dl;
        recordCount++;
    }

    // Copy Constructor
    PersonnelInfo(const PersonnelInfo &p) {
        name = p.name;
        dob = p.dob;
        bloodGroup = p.bloodGroup;
        height = p.height;
        weight = p.weight;
        insurancePolicyNumber = p.insurancePolicyNumber;
        contactAddress = p.contactAddress;
        telephoneNumber = p.telephoneNumber;
        drivingLicenseNumber = p.drivingLicenseNumber;
        recordCount++;
    }

    // Destructor
    ~PersonnelInfo() {
        recordCount--;
    }

    // Setter functions
    inline void setName(string n) { name = n; }
    inline void setDob(string d) { dob = d; }
    inline void setBloodGroup(string bg) { bloodGroup = bg; }
    inline void setHeight(float h) { height = h; }
    inline void setWeight(float w) { weight = w; }
    inline void setInsurancePolicyNumber(string ipn) { insurancePolicyNumber = ipn; }
    inline void setContactAddress(string ca) { contactAddress = ca; }
    inline void setTelephoneNumber(string tn) { telephoneNumber = tn; }
    inline void setDrivingLicenseNumber(string dl) { drivingLicenseNumber = dl; }

    // Getter functions
    string getInsurancePolicyNumber() { return insurancePolicyNumber; }

    // Static function to get the record count
    static int getRecordCount() {
        return recordCount;
    }

    // Function to accept new data
    void accept() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Date of Birth (dd/mm/yyyy): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Height (in cm): ";
        cin >> height;
        cout << "Enter Weight (in kg): ";
        cin >> weight;
        cin.ignore();
        cout << "Enter Insurance Policy Number: ";
        getline(cin, insurancePolicyNumber);
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Enter Driving License Number: ";
        getline(cin, drivingLicenseNumber);
    }

    // Display function (in table format)
    void display() {
        cout << left << setw(15) << name << setw(15) << dob << setw(10) << bloodGroup << setw(8) << height
             << setw(8) << weight << setw(20) << insurancePolicyNumber << setw(25) << contactAddress 
             << setw(15) << telephoneNumber << setw(20) << drivingLicenseNumber << endl;
    }
};

// Initialize static member
int PersonnelInfo::recordCount = 0;

// Global vector to hold personnel data
vector<PersonnelInfo*> database;

// Function to display the table header
void displayTableHeader() {
    cout << left << setw(15) << "Name" << setw(15) << "DOB" << setw(10) << "Blood Grp" << setw(8) << "Height"
         << setw(8) << "Weight" << setw(20) << "Insurance Policy" << setw(25) << "Contact Address"
         << setw(15) << "Phone" << setw(20) << "Driving License" << endl;
    cout << string(130, '-') << endl;
}

// Function to search personnel by insurance policy number
PersonnelInfo* searchByPolicyNumber(string policyNumber) {
    for (PersonnelInfo* p : database) {
        if (p->getInsurancePolicyNumber() == policyNumber) {
            return p;
        }
    }
    return nullptr;
}

// Function to delete personnel by policy number
void deleteByPolicyNumber(string policyNumber) {
    for (size_t i = 0; i < database.size(); i++) {
        if (database[i]->getInsurancePolicyNumber() == policyNumber) {
            delete database[i];  // Free memory
            database.erase(database.begin() + i);  // Remove from vector
            cout << "Record with policy number " << policyNumber << " deleted." << endl;
            return;
        }
    }
    cout << "Record with policy number " << policyNumber << " not found!" << endl;
}

// Main function using switch-case
int main() {
    int choice;
    
    do {
        cout << "\nPersonnel Information System Menu" << endl;
        cout << "1. Add Personnel Information" << endl;
        cout << "2. Display All Personnel Information" << endl;
        cout << "3. Search by Insurance Policy Number" << endl;
        cout << "4. Modify Personnel Information by Policy Number" << endl;
        cout << "5. Delete Personnel Information by Policy Number" << endl;
        cout<<"6. Display Avalable records"<<endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                PersonnelInfo *p = new PersonnelInfo();
                p->accept();
                database.push_back(p);
                break;
            }
            case 2: {
                if (!database.empty()) {
                    displayTableHeader();
                    for (PersonnelInfo *p : database) {
                        p->display();
                    }
                } else {
                    cout << "No records found!" << endl;
                }
                break;
            }
            case 3: {
                string policyNumber;
                cout << "Enter the insurance policy number to search: ";
                cin.ignore();
                getline(cin, policyNumber);
                PersonnelInfo* result = searchByPolicyNumber(policyNumber);
                if (result) {
                    displayTableHeader();
                    result->display();
                } else {
                    cout << "No personnel with policy number " << policyNumber << " found!" << endl;
                }
                break;
            }
            case 4: {
                string policyNumber;
                cout << "Enter the insurance policy number to modify: ";
                cin.ignore();
                getline(cin, policyNumber);
                PersonnelInfo* result = searchByPolicyNumber(policyNumber);
                if (result) {
                    cout << "Modifying information for policy number " << policyNumber << "..." << endl;
                    result->accept();  // Call accept() to modify the data
                } else {
                    cout << "No personnel with policy number " << policyNumber << " found!" << endl;
                }
                break;
            }
            case 5: {
                string policyNumber;
                cout << "Enter the insurance policy number to delete: ";
                cin.ignore();
                getline(cin, policyNumber);
                deleteByPolicyNumber(policyNumber);
                break;
            }
            case 6:
               
                cout<<"Total records is: "<<PersonnelInfo::getRecordCount()<<endl;
                break;
            case 7: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 7);

    // Freeing dynamically allocated memory
    for (PersonnelInfo* p : database) {
        delete p;
    }
    database.clear();

    return 0;
}
