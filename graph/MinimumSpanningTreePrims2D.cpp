#include <bits/stdc++.h>

using namespace std;

#define V 5

int getLeastKey(vector<int>& keySet, vector<bool>& mstSet)
{
    int minIndex, minKey = INT_MAX;
    for (int index=0; index<V; index++)
    {
        if (mstSet[index] == false && minKey > keySet[index])
        {
            minIndex = index;
            minKey = keySet[index];
        }
    }
    return minIndex;
}

void PrintPrimsMST(int parent[], int graph[V][V])
{
    cout<<"Edge\tWeight"<<endl;
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

void PrintPrimsMST(int graph[V][V])
{
    vector<int>  parent(V);
    vector<int>  keySet(V, INT_MAX);
    vector<bool> mstSet(V, false);

    parent[0] = -1;
    keySet[0] =  0; // start with vertex "0"

    for(int count=0; count < V-1; count++)
    {
        int u = getLeastKey(keySet, mstSet);

        mstSet[u] = true;
        for (int v=0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < keySet[v])
            {
                parent[v] = u;
                keySet[v] = graph[u][v];
            }
        }
    }

    PrintPrimsMST(parent, graph);
}

int main()
{
    int graph[V][V] =
    {
        { 0,  3,  2,  0, 0 },
        { 3,  0, 16, 12, 0 },
        { 2, 16,  0,  0, 5 },
        { 0, 12,  0,  0, 0 },
        { 0,  0,  5,  0, 0 }
    };

    PrintPrimsMST(graph);

    return 0;
}
