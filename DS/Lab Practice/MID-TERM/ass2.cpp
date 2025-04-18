#include <iostream>

using namespace std;

class BST
{
public:
    int id;
    string name;
    BST *LC;
    BST *RC;

    // Default Construcotr
    BST() : LC(NULL), RC(NULL) {}
    void create();
    void insert(BST *root, BST *next);
    void inorder(BST *root);
    void mirror(BST *root);
};

BST *root = NULL;

void BST::create()
{
    root = new BST;
    cout << "Enter Id: ";
    cin >> root->id;
    cout << "Enter Name: ";
    cin >> root->name;
    root->LC = NULL;
    root->RC = NULL;

    int ch;
    do
    {
        cout << "Enter Add Node (1/0)?";
        cin >> ch;
        if (ch == 1)
        {
            BST *newNode = new BST;
            cout << "Enter Id: ";
            cin >> newNode->id;
            cout << "Enter Name: ";
            cin >> newNode->name;
            newNode->RC = NULL ;
            newNode->LC = NULL;
            insert(root, newNode);
        }
    } while (ch != 0);
}

void BST::insert(BST *root, BST *next)
{
    if (root == NULL)
    {
        return;
    }
    if (next->id < root->id)
    {
        if (root->LC == NULL)
        {
            root->LC = next;
        }
        else
        {
            insert(root->LC, next);
        }
    }
    else
    {
        if (root->RC == NULL)
        {
            root->RC = next;
        }
        else
        {
            insert(root->RC, next);
        }
    }
}

void BST::inorder(BST *root){
    if(root==NULL){
        return;
    }
    inorder(root->LC);
    cout<<"ID: "<<root->id<<endl;
    inorder(root->RC);
}

void BST::mirror(BST *root){
    if (root==NULL)
    {
        return;
    }
    mirror(root->LC);
    mirror(root->RC);
    swap(root->RC,root->LC);
}

int main()
{
    BST b;
    b.create();
    b.inorder(root);
    b.mirror(root);
    b.inorder(root);

    return 0;
}