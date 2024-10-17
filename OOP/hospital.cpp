#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    int id;
    string name, ds;
    virtual void accept() = 0;
    virtual void display() = 0;
};

class Doctor:public Person
{
    int sal;
public:
    // Write Deinations All Functions
    void accept(){
        // Accpet Details
        cout<<"Enter Doctor ID: ";
        cin>>id;
        cout<<"Enter Doctor Name: ";
        cin>>name;
        cout<<"Enter Doctor Designation: ";
        cin>>ds;
        cout<<"Enter Doctor Salary: ";
        cin>>sal;
    };
    // Write Deinations All Functions
    void display(){
        cout<<"\n"<<id<<"\t"<<name<<"\t"<<ds<<"\t"<<sal<<endl;
    };
};

class AStaff:public Person
{
    int sal;
public:
    // Write Deinations All Functions
    void accept(){
        // Accpet Detais
        cout<<"Enter Staff ID: ";
        cin>>id;
        
    };
    // Write Deinations All Functions
    void display(){
        cout<<"\n"<<id<<"\t"<<name<<"\t"<<ds<<"\t"<<sal<<endl;
    };
};

class Patient:public Person
{
    int bill;
public:
    // Write Deinations All Functions
    void accept();
    // Write Deinations All Functions
    void display(){
        cout<<"\n"<<id<<"\t"<<name<<"\t"<<ds<<"\t"<<bill<<endl;
    };
};

int main()
{

    return 0;
}