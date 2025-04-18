#include <iostream>
#define INF 99999999
#define SIZE 10

using namespace std;

class Job
{
public:
    int V;
    int graph[SIZE][SIZE];
    int parent[SIZE];
    int key[SIZE];
    bool visit[SIZE];

    // Contructor
    Job(int vertices)
    {
        V = vertices;
        for (int i = 0; i < SIZE; i++)
        {
            parent[i] = 0;
            key[i] = INF;
            visit[i] = false;
            for (int j = 0; j < SIZE; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

    // Geting Values of Graph or adjacent
    void inputGraph()
    {
        cout << "Enter the adjacency matrix representing the distance between cities: " << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    // Function for finding the Minimum Key
    int findMinKey()
    {
        int min = INF, minIndex = -1;
        for (int i = 0; i < V; i++)
        {
            if (!visit[i] && key[i] < min)
            {
                min = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // primt MSt algo
    void primMST()
    {
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++)
        {
            int u = findMinKey();
            visit[u] = true;

            for (int i = 0; i < V; i++)
            {
                if (graph[u][i] && !visit[i] && graph[u][i] < key[i])
                {
                    key[i] = graph[u][i];
                    parent[i] = u;
                }
            }
        }
    }

    // Printing The Minimum Spanning Tree
    void printMST()
    {   
        cout << "Edge \tWeight" << endl;
        int sumWeight =0 ;
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
            sumWeight += graph[i][parent[i]];
        }

        cout<<"Total Weight is: "<<sumWeight <<endl;
    }
};

int main(){
    int V;
    cout << "Enter the number of cities (nodes) (max 10): ";
    cin >> V;
    
    if (V > SIZE) {
        cout << "Error: Maximum number of cities allowed is " << SIZE << "." << endl;
        return 1;
    }
    
    Job job(V);
    job.inputGraph();
    job.primMST();
    job.printMST();
    
    return 0;
}