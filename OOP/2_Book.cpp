#include <iostream>
#include <vector>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int price;
    int quantity;
    string publisher;

public:
    Book(string title, string author, string publisher, int price, int quantity)
    {

        this->title = title;
        this->author = author;
        this->price = price;
        this->quantity = quantity;
        this->publisher = publisher;
        cout << "Book Succesfully Added." << endl;
    }
    void display()
    {
        cout << title << "\t" << author << "\t" << publisher << "\t" << quantity << "\t" << price;
    }
    string getTitle()
    {
        return this->title;
    }
    string getAuthor()
    {
        return this->author;
    }
    int getprice()
    {
        return this->price;
    }
    int getQuantity()
    {
        return this->quantity;
    }
    string getPublisher()
    {
        return this->publisher;
    }
};

vector<Book> B;

// Search By title And Author
void SearchByTitleAuthor()
{
    string title, author;
    int cost,q;
    int quantitys;
    int totalAmount;
    cout << "Enter the title of the book: ";
    cin >> title;
    cout << "Enter the Author of the book: ";
    cin >> author;
    int flag = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if ((B[i].getAuthor() == author) && (B[i].getTitle() == title))
        {
            cout << "Title: " << B[i].getTitle() << endl;
            cout << "Author: " << B[i].getAuthor() << endl;
            flag = 1;
            if (B[i].getQuantity() == 0)
            {
                cout << "Quantity: Out of Stock" << endl;
                break;
            }
            else
            {
                // Print the Quantity of the book is  Available
                cout << "Quantity: " << B[i].getQuantity() << "Available" << endl;
                cout <<"How much Copies you want : ";
                cin>>quantitys;
                if(quantitys<B[i].getQuantity()){
                    cout<<"Total Amount is : "<<(B[i].getprice())*quantitys<<" . You Have To PAY."<<endl;
                }
                else{
                    cout<<"Sorry We Have Only "<<B[i].getQuantity()<<"Copies."<<endl;
                }
            }
        }
    }
    if (flag == 0)
    {
        cout << "Book Is Not Found / Not Available." << endl;
    }
}

void Display()
{
    cout << "\nTitle\tAuthor\tPublisher\tQuantity\tPrice" << endl;
    for (int i = 0; i < B.size(); i++)
    {
        B[i].display();
    }
}

int main()
{
    // Book temp;
    int ch = 0;
    int flag = 0;
    string title;
    string author;
    int price;
    int quantity;
    string publisher;

    while (ch != 4)
    {
        // here Switch Case
        // Accept 2. Display 3. Search 4. Exit
        cout << "\n1. Accept \n2. Display \n3. Search \n4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Title Of the Book: ";
            cin >> title;
            cout << "Enter Author Of the Book: ";
            cin >> author;
            cout << "Enter Publisher Of the Book: ";
            cin >> publisher;
            cout << "Enter Quantity Of the Book: ";
            cin >> quantity;
            cout << "Enter Price Of the Book: ";
            cin >> price;
            flag=0;
            for (int i = 0; i < B.size(); i++)
            {
                if ((B[i].getAuthor() == author) && (B[i].getTitle() == title))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                B.push_back(Book(title, author, publisher, quantity, price));
            }
            break;
        case 2:
            Display();
            break;
        case 3:
            SearchByTitleAuthor();
            break;
        case 4:
            // Destructure 
            for (int i = 0; i < B.size(); i++){
                B[i].~Book();
            }
            cout << "exiting.." << endl;
            break;
        default:
            cout << "Enter Correct Choice." << endl;
            break;
        }
    }

    return 0;
}