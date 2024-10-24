/*
Problem Statement : create a class that name is television that has data member to hold model number, screen size and the prize.
member function include overloaded insertion and extraction operator if more than 4 digits are entered for the model number, if the screen size small than 12 or grater than 70 inches or if the prize is negative or over 5000 dollar then throw and integer wite a main function that instance create television object, allow user to enter data and display the data members if an exception is called replace all the data value with 0 value.
*/


#include <iostream>
#include <stdexcept>

using namespace std;

class Television {
private:
    int modelNumber;
    int screenSize;
    double price;

public:
    // Constructor to initialize default values
    Television() : modelNumber(0), screenSize(0), price(0.0) {}

    // Friend functions to overload the insertion (<<) and extraction (>>) operators
    friend ostream& operator<<(ostream& out, const Television& tv);
    friend istream& operator>>(istream& in, Television& tv);

    // Member function to reset values to 0
    void reset() {
        modelNumber = 0;
        screenSize = 0;
        price = 0.0;
    }
};

// Overloading extraction (>>) operator to input data with validation
istream& operator>>(istream& in, Television& tv) {
    cout << "Enter model number: ";
    in >> tv.modelNumber;
    if (tv.modelNumber < 1000 || tv.modelNumber > 9999) {
        throw 1;  // Model number should be exactly 4 digits
    }

    cout << "Enter screen size (in inches): ";
    in >> tv.screenSize;
    if (tv.screenSize < 12 || tv.screenSize > 70) {
        throw 2;  // Screen size should be between 12 and 70 inches
    }

    cout << "Enter price (in dollars): ";
    in >> tv.price;
    if (tv.price < 0 || tv.price > 5000) {
        throw 3;  // Price should be between 0 and 5000 dollars
    }

    return in;
}

// Overloading insertion (<<) operator to output data
ostream& operator<<(ostream& out, const Television& tv) {
    out << "Model Number: " << tv.modelNumber << "\n";
    out << "Screen Size: " << tv.screenSize << " inches\n";
    out << "Price: $" << tv.price << "\n";
    return out;
}

int main() {
    Television tv;

    try {
        // Input data from the user
        cin >> tv;

        // Display data if everything is valid
        cout << "\nTelevision Details:\n";
        cout << tv;
    } catch (int error) {
        // Handle exceptions and reset all values to 0
        cout << "Invalid input! Error code: " << error << ". Resetting values to 0.\n";
        tv.reset();

        // Display the reset values
        cout << "\nTelevision Details (after reset):\n";
        cout << tv;
    }

    return 0;
}
