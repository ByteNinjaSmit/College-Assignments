#include<iostream>
using namespace std;

class BT{
    public:
        int id;
        string name;
        BT *LC =NULL;
        BT *RC =NULL;

        // Default Constructor
        BT():LC(NULL),RC(NULL){}
        void create();
        void insert(BT *root, BT *next);
        void inorder(BT *root);
        int height(BT *root);
};

BT *root =NULL;

void BT::create(){
    int ch = 0;
    root = new BT;
    cout<<"Enter Id: ";
    cin>>root->id;
    cout<<"Enter Name: ";
    cin>>root->name;

    // define Null LC & RC
    root->LC = NULL;
    root->RC=NULL;

    do{
        cout<<"Do You Want to add Another Node (1/0) ?";
        cin>>ch;
        if(ch==1){
            BT *newNode= new BT;
            cout<<"Enter Id";
            cin>>newNode->id;
            cout<<"Enter Name: ";
            cin>>newNode->name;

            // Define Null LC & RC
            newNode->LC = NULL;
            newNode->RC=NULL;
            insert(root,newNode);
        }
    }while(ch!=0);
}

void BT::insert(BT *root, BT *next){
    char side;
    cout<<"Which side of "<<root->id<<" do you want insert ? (L/R)";
    cin>>side;
    if(side == 'L' || side == 'l'){
        if(root->LC == NULL){
            root->LC = next;
        }else{
            insert(root->LC,next);
        }
    }else if(side =='R' || side=='r'){
        if(root->RC == NULL){
            root->RC=next;
        }else{
            insert(root->RC,next);
        }
    }else{
        cout<<"Invalid Choice. Please Enter L or R"<<endl;
    }
}

void BT::inorder(BT* root){
    if(root==NULL){
        return;
    }
    inorder(root->LC);
    cout<<"ID: "<<root->id<<endl;
    cout<<"Name: "<<root->name<<endl;
    inorder(root->RC);
}

int BT::height(BT *root){
    if(root==NULL){
        return 0;
    }
    int LHT = height(root->LC);
    int RHT = height(root->RC);

    return max(LHT,RHT)+1;
}

int main(){


    return 0;
}