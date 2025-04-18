#include<iostream>
#include<string>
using namespace std;

#define MAX_CITIES 100

class Graph{
    public:
        int CitiesNo;
        string cities[MAX_CITIES];
        int adjMatrix[MAX_CITIES][MAX_CITIES];

        struct Node{
            int ciyIndex;
            int fuel;
            Node* next;
        };

        Node* adjList[MAX_CITIES];
        Graph(){
        for(int i = 0;i<MAX_CITIES;i++){
            adjList[i]=NULL;
        }}

        void accept(){
            cout<<"Enter total number of cities: ";
            cin>>CitiesNo;

            for(int i = 0;i<CitiesNo;i++){
                cout<<"Enter The Name Of city: ";
                cin>>cities[i];
            }
            cout<<"Enter Flight path(fuel cost), enter 0 if no flight: \n";
            for(int i=0;i<CitiesNo;i++){
                for(int j=0;j<CitiesNo;j++){
                    if(i==j){
                        adjMatrix[i][j]=0;
                    }
                    else{
                        cout<<"Fuel Required from "<<cities[i]<<" to "<<cities[j]<<" :";
                        cin>>adjMatrix[i][j];
                        if(adjMatrix[i][j]>0){
                            addEdge(i,j,adjMatrix[i][j]);
                        }
                    }
                }
            }
        }

        void addEdge(int src, int dest, int fuel){
            Node * newNode = new Node();
            newNode->ciyIndex = dest;
            newNode->fuel = fuel;
            newNode->next=adjList[src];
            adjList[src] = newNode;

        }

        void displayMatrix(){
            cout<<"matrix Representation"<<endl;
            cout<<" ";
            for(int i = 0;i<CitiesNo;i++){
                cout<<cities[i]<<"\t";
            }
            cout<<endl;

            for(int i=0;i<CitiesNo;i++){
                cout<<cities[i]<<"\t";
                for(int j=0;j<CitiesNo;j++){
                    cout<<adjMatrix[i][j]<<"\t";
                }
                cout<<endl;
            }
        }

        void displayList(){
            for(int i =0;i<CitiesNo;i++){
                cout<<cities[i]<<"->";
                Node *temp = adjList[i];
                while(temp){
                    cout<<cities[temp->ciyIndex]<<temp->fuel;
                    temp=temp->next;
                }
            }
        }

};



int main(){
    Graph g;
    g.accept();
    g.displayMatrix();
    return 0;
}