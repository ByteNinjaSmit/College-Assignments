#include<iostream>
using namespace std;

class Op{
    double r,i;
    public:
        //   Parametrized Constructor 
        Op(double r=0,double i=0){
            this->r= r;
            this->i=i;
        }
        // Display Fucntion
        void display(){
        if (i >= 0)
            cout << r << " + " << i << "i" << endl;
        else
            cout << r << " - " << -i << "i" << endl;
        }

        // Operator Overloading
        Op operator+(const Op& s);
        Op operator-(const Op& s);
        Op operator*(const Op& s);
        Op operator/(const Op& s);
};

// Addition
Op Op::operator+(const Op& c2){
    return Op(r+c2.r,i+c2.i);
}
//Subtraction
Op Op::operator-(const Op& c2){
    return Op(r-c2.r,i-c2.i);
}

// Multiplication
Op Op::operator*(const Op& c2){
    return Op(r*c2.r - i*c2.i, r*c2.i + i*c2.r);
}

// Division
Op Op::operator/(const Op& c2){
    if(c2.r == 0 && c2.i == 0)
        throw runtime_error("Division by zero is not allowed");
    double denominator = c2.r*c2.r + c2.i*c2.i;
    return Op((r*c2.r + i*c2.i) / denominator, (i*c2.r - r*c2.i) / denominator);
}

int main(){
    Op c1, c2, result;
    double r1, i1, r2, i2;
    int choice = 0;

    // Input two complex numbers
    cout << "Enter the real and imaginary part of the first complex number: ";
    cin >> r1 >> i1;
    c1 = Op(r1, i1);

    cout << "Enter the real and imaginary part of the second complex number: ";
    cin >> r2 >> i2;
    c2 = Op(r2, i2);

    // While Loop
    while (choice != 5)
    {
        // Switch case for operation selection
        cout << "Choose the operation to perform on complex numbers:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            result = c1 + c2;
            cout << "Result of Addition: ";
            result.display();
            break;
        case 2:
            result = c1 - c2;
            cout << "Result of Subtraction: ";
            result.display();
            break;
        case 3:
            result = c1 * c2;
            cout << "Result of Multiplication: ";
            result.display();
            break;
        case 4:
            try
            {
                result = c1 / c2;
                cout << "Result of Division: ";
                result.display();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        case 5:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}