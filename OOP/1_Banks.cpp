// Assignment 1st Of OOP Lab
// Author: Smitraj Dinkar Bankar
// Problem Defination: Creating A Bank Account And Performing real World Operations
// Date: 07/08/2024
// 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyBank
{
private:
    int AccountNo, Amount;
    string AccountName, Password;

public:
    void setAccount()
    {
        cout << "Set Your Bank Account No: ";
        cin >> this->AccountNo;
        cout << "\n Enter your Account Name: ";
        cin >> this->AccountName;
        cout << "\n Set Your Password: ";
        cin >> this->Password;
    }
    void Deposit()
    {
        int amount;
        string pas;
        cout << "\nEnter Your Password: ";
        cin >> pas;
        if (pas == this->Password)
        {
            cout << "\nEnter the amount to deposit: ";
            cin >> amount;
            this->Amount += amount;
            cout << "\nAmount deposited successfully. Your current balance is: " << this->Amount << endl;
        }
        else
            cout << "\nPassword Incorrect!";
    }
    void Withdraw()
    {
        int amount;
        string pas;
        cout << "\nEnter Your Password: ";
        cin >> pas;
        if (pas == this->Password)
        {
            cout << "\nEnter the amount to withdraw: ";
            cin >> amount;
            if (this->Amount >= amount)
            {
                this->Amount -= amount;
                cout << "\nAmount withdrawn successfully. Your current balance is: " << this->Amount << endl;
            }
            else
                cout << "\nInsufficient balance!";
        }
        else
        {
            cout << "Password Incorrect!" << endl;
        }
    }
    void display()
    {
        cout << "\nAccount No: " << this->AccountNo;
        cout << "\nAccount Name: " << this->AccountName;
    }
    void DisplayBalance()
    {
        string pas;
        cout << "\nEnter Your Password: ";
        cin >> pas;
        if (pas == this->Password)
        {
            cout << "\nYour current balance is: " << this->Amount << endl;
        }
        else
        {
            cout << "Password Incorrect!" << endl;
        }
    }
    int getAccountNumber()
    {
        return this->AccountNo;
    }
};

vector<MyBank> Bank;

int main()
{
    MyBank B;
    int Acc;
    int ch = 0;
    while (ch != 6)
    {
        cout << "\n1. Create New Account\n2. Deposit\n3. Withdraw\n4. Display Account Details\n5. Display Balance\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            B.setAccount();
            Bank.push_back(B);
            break;
        }

        case 2:
            // int Acc;
            cout << "\nEnter Account Number: ";
            cin >> Acc;
            for (int i = 0; i < Bank.size(); i++)
            {
                if (Bank[i].getAccountNumber() == Acc)
                {
                    Bank[i].Deposit();
                    break;
                }
            }
        case 3:
            // int Acc;
            cout << "\nEnter Account Number: ";
            cin >> Acc;
            for (int i = 0; i < Bank.size(); i++)
            {
                if (Bank[i].getAccountNumber() == Acc)
                {
                    Bank[i].Withdraw();
                    break;
                }
            }
        case 4:
            // int Acc;
            cout << "\nEnter Account Number: ";
            cin >> Acc;
            for (int i = 0; i < Bank.size(); i++)
            {
                if (Bank[i].getAccountNumber() == Acc)
                {
                    Bank[i].display();
                    break;
                }
            }
        case 5:
            // int Acc;
            cout << "\nEnter Account Number: ";
            cin >> Acc;
            for (int i = 0; i < Bank.size(); i++)
            {
                if (Bank[i].getAccountNumber() == Acc)
                {
                    Bank[i].DisplayBalance();
                    break;
                }
            }
            break;
        case 6:
        cout << "\nExiting Program...\n";
        default:
            break;
        }
    }

    return 0;
}