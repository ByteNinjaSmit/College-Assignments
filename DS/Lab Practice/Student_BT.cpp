#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
        string name;
        int id;

        // Binary Tree Left Child & Right Child
        Student *LC, *RC;

        void create();
        void insert(Student *root);
        void inOrder(Student *root);
        int height(Student *root);
};

Student *root, *Stack[100];

// Create a First Root Node Of Binary Tree
void Student::create(){
    
}

int main(){


    return 0;
}