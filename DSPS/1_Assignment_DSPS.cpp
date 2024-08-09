// Assignment 1st of DSPS Lab
// Problem Statement: Linear Search & Sort Using Object
// Authour : Smitraj Dinkar Bankar
// Date : 25 / 07 / 2024

#include <iostream>
#include <vector>
using namespace std;

class LSearch
{
private:
    vector<int> arr;

public:
    void accept_array()
    {
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        arr.resize(n); // Resize the vector to hold 'n' elements
        cout << "Enter the elements of array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void display_array()
    {
        cout << "Elements in the array: ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void linear_search()
    {
        int item, index;
        cout << "Enter the element to search: ";
        cin >> item;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == item)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            cout << "Element found at index " << index << endl;
        }
        else
        {
            cout << "Element not found in the array" << endl;
        }
    }
    void countOccurrences()
    {
        int item, count = 0;
        cout << "Enter the element to count occurrences: ";
        cin >> item;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == item)
            {
                count++;
            }
        }
        cout << "Element " << item << " occurs " << count << " times in the array" << endl;
    }
    void findFirstAndLastOccurrence()
    {
        int item, first_index = -1, last_index = -1;
        cout << "Enter the element to find first and last occurrence: ";
        cin >> item;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == item)
            {
                if (first_index == -1)
                {
                    first_index = i;
                }
                last_index = i;
            }
        }
        if (first_index != -1)
        {
            cout << "Element " << item << " first occurs at index " << first_index << endl;
            cout << "Element " << item << " last occurs at index " << last_index << endl;
        }
        else
        {
            cout << "Element not found in the array" << endl;
        }
    }
};

int main()
{
    LSearch obj;
    int ch;
    while (ch != 6)
    {
        cout << "\n\n1. Accept array\n2. Display array\n3. Linear search\n4. Count occurrences\n5. Find first and last occurrence\n6. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.accept_array();
            break;
        case 2:
            obj.display_array();
            break;
        case 3:
            obj.linear_search();
            break;
        case 4:
            obj.countOccurrences();
            break;
        case 5:
            obj.findFirstAndLastOccurrence();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please choose a valid option.\n";
            break;
        }
    }

    return 0;
}