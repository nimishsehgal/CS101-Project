#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
 
#define V 15
 
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 
void primMST(int graph[V][V])
{
    int parent[V];
 
    int key[V];
 
    bool mstSet[V];
 
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;
   
    parent[0] = -1;
 
    for (int count = 0; count < V - 1; count++) {
         
        int u = minKey(key, mstSet);
 
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
 
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8},
                        { 2, 0, 2, 2, 6, 3, 8, 7, 2, 5, 3, 4, 3, 3, 2},
                        { 8, 2, 0, 7, 9, 6, 8, 7, 2, 9, 10, 3, 8, 10, 6},
                        { 5, 2, 7, 0, 5, 4, 2, 3, 4, 4, 5, 2, 2, 4, 9},
                        { 1, 6, 9, 5, 0, 8, 5, 3, 8, 8, 10, 4, 2, 10, 9},
                        { 10, 3, 6, 4, 8, 0, 7, 6, 1, 3, 9, 7, 1, 3, 5},
                        { 5, 8, 8, 2, 5, 7, 0, 9, 7, 6, 1, 10, 1, 1, 7},
                        { 9, 7, 7, 3, 3, 6, 9, 0, 2, 4, 9, 10, 4, 5, 5},
                        { 9, 2, 2, 4, 8, 1, 7, 2, 0, 7, 1, 7, 7, 2, 9},
                        { 3, 5, 9, 4, 8, 3, 6, 4, 7, 0, 5, 10, 7, 4, 8},
                        { 5, 3, 10, 5, 10, 9, 1, 9, 1, 5, 0, 9, 9, 3, 10},
                        { 6, 4, 3, 2, 4, 7, 10, 10, 7, 10, 9, 0, 2, 4, 6},
                        { 6, 3, 8, 2, 2, 1, 1, 4, 7, 7, 9, 2, 0, 10, 9},
                        { 2, 3, 10, 4, 10, 3, 1, 5, 2, 4, 3, 4, 10, 0, 5},
                        { 8, 2, 6, 9, 9, 5, 7, 5, 9, 8, 10, 6, 9, 5, 0}, 
                        };

    auto start = high_resolution_clock::now();
    primMST(graph);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<< "Time taken by function: "<< duration.count() << " microseconds"<<endl;

    return 0;
}
 