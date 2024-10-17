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