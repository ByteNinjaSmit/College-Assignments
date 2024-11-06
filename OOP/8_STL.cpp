// To Create a function template for selection sort that can sort array of various type such as integer floats characters

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function for Selection Sort
template <class T> // T is a type parameter
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <class T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int ch = 0;
    int n;

    while (ch != 4)
    {
        cout << "1. Integer Array" << endl;
        cout << "2. Float Array" << endl;
        cout << "3. Character Array" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            // Integer 
            cout << "Enter the number of elements: ";
             cin >> n;
            int* arr = new int[n]; // Dynamic allocation for integer array
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            selectionSort(arr, n);
            cout << "Sorted array: ";
            printArray(arr, n);
            delete[] arr; // Free the allocated memory
            break;
        }
        case 2:
        {
            //  Double
            cout << "Enter the number of elements: ";
            cin >> n;
            float* arr = new float[n]; // Dynamic allocation for float array
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            selectionSort(arr, n);
            cout << "Sorted array: ";
            printArray(arr, n);
            delete[] arr; // Free the allocated memory
            break;
        }
        case 3:
        {
            // Character
            cout << "Enter the number of elements: ";
            cin >> n;
            char* arr = new char[n]; // Dynamic allocation for char array
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            selectionSort(arr, n);
            cout << "Sorted array: ";
            printArray(arr, n);
            delete[] arr; // Free the allocated memory
            break;
        }
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }
    }

    return 0;
}