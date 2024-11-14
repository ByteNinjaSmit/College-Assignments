/*
Problem Defination:  Impliment a C++ program consisting a base class with data member such as name of the student, roll no and subject
the derived class consist as  data member such subject code, CIA maerks, end sem marks, the sport class consist of sport name and sport grade and final result class consist of total marks of the student along with percentage, display the student grade card by usign result class object.
prgram should have following facilities. 1) build a mastertable 2) List a table 3) Insert new Entry 4) Delete an Old entry 5) Edit an entry 6)search the particular student record use the concept of inheritance


Name: Bankar Smitraj Dinkar
Class: SY (A)

*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Student
{
private:
    int roll_no;
    string name, prn;

public:
    void acceptS()
    {
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Your NameL ";
        cin >> name;
        cout << "Enter Your PRN: ";
        cin >> prn;
    }
    void display()
    {
        cout << "Name: " << name << "\nRoll No: " << roll_no << "\nPRN: " << prn << endl;
    }
};

class Test : virtual public Student
{
    string sub[5];
    int C[5], E[5];

public:
    void acceptT()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter Your Subject Name " << i << ": ";
            cin >> sub[i];
            cout << "Enter Marks CIA & ESE OF " << sub[i] << ": ";
            cin >> C[i] >> E[i];
        }
    }
    void displayT()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Your Marks CIA & ESE OF " << sub[i] << ": " << C[i] << " " << E[i] << endl;
        }
    }
};

class Sport : public virtual Student
{
    string sportname, sportGrade;

public:
    void acceptG()
    {
        cout << "Enter Your Sport Name: ";
        cin >> sportname;
        cout << "Enter Your Sport Grade: ";
        cin >> sportGrade;
    }
    void displayG()
    {
        cout << "Your "<<sportname<<" Grade: "<<sportGrade<<endl;
    }
};

class Result:public Test, public Sport{
    public:
    void displayAll(){
        display();
        displayT();
        displayG();
    }
};

// vector<Result> R;

int main(){
    Result Temp;
    int ch=0;
    while(ch!=5){
        cout<<"\n1. Accept Student\n2. Accept Test Marks\n3. Accept Grade\n4. Display\n5. Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            Temp.acceptS();
            // R.push_back(Temp);
            break;
        case 2:
            Temp.acceptT();
            // R.push_back(Temp);
            break;
        case 3:
            Temp.acceptG();
            // R.push_back(Temp);
            break;
        case 4:
            // for (int i = 0; i < R.size(); i++)
            // {
                Temp.displayAll();
            // }
            break;
        case 5:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Enter Correct Choice"<<endl;
            break;
        }
    }
    return 0;
}