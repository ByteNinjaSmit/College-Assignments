#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Student {
    int id;
    string name;
    Student *LC, *RC;

public:
    Student() : LC(NULL), RC(NULL) {}
    void create();
    void insert(Student *root, Student *next);
    void display(Student *root);
    void displayInorderNonRecursive(Student *root);
    void leafNode(Student *root);
    void internalNode(Student *root);
    int height(Student *root);
    void mirror(Student *root);
    void search(Student *root, int searchId);
};

