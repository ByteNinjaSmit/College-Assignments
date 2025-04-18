#include<iostream>
using namespace std;
#define INF 9999
#define MAX 100

class MST{
    public:
        int V;
        int graph[MAX][MAX];
        int parent[MAX];
        int key[MAX];
        bool visit[MAX];

        MST(int vertices){
            V = vertices;
            for(int i = 0; i<MAX;i++){
                parent[i]=0;
                key[i]=INF;
                visit[i]=false;
                for(int j=0;j<MAX;j++){
                    graph[i][j]=0;
                }
            }
        }

        void inputGraph(){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    cin>>graph[i][j];
                }
            }
        }

        int findMinKey(){
            int min = INF;
            int minIndex =-1;
            for(int v = 0;v<V;v++){
                if(!visit[v] && key[v]<min){
                    min = key[v];
                    minIndex = v;
                }
            }
            return minIndex;
        }

        void primMST(){
            key[0] = 0;
            parent[0] = -1;

            for(int count = 0;count<V;count++){
                int u = findMinKey();
                visit[u] = true;
                for (int v = 0;v<V;v++){
                    if(graph[u][v] && !visit[v] && graph[u][v] < key[v]){
                        key[v] = graph[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        void display() {
            cout << "Minimum Spanning Tree Edges:\n";
            for (int i = 1; i < V; i++) { 
                cout << "Edge: " << parent[i] << " - " << i << " | Weight: " << graph[i][parent[i]] << endl;
            }
        }
};

int main(){

    int v;
    cin>>v;
    MST m(v);
    m.inputGraph();
    m.primMST();
    m.display();

    return 0;
}