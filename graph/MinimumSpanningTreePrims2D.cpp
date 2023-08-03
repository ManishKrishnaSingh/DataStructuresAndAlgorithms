#include <bits/stdc++.h>

using namespace std;

int minIndexByDistance(vector<int>& weight, vector<bool>& visited, int V)
{
    int minIndex, minValue=INT_MAX;
    for(int v = 0; v < V; v++)
    {
        if(!visited[v] and minValue >= weight[v])
        {
            minIndex = v;
            minValue = weight[v];
        }
    }
    return minIndex;
}

void PrimsMinimumSpanningTree(vector<vector<int>>& graph)
{
    if(graph.size()==0 || graph[0].size()==0)
    {
        return;
    }

    int V = graph.size();

    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);

    vector<bool> visited(V, false);

    weight[0] = 0; // start with vertex "0"
    for(int counter=0; counter < V; counter++)
    {
        int u = minIndexByDistance(weight, visited, V);

        visited[u] = true;

        for (int v=0; v < V; v++)
        {
            if(!visited[v] and graph[u][v] and weight[v] > graph[u][v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    // Print Prims MST
    cout<<"Edge\tWeight"<<endl;
    for(int v = 0; v < V; v++)
    {
        if(parent[v] != -1)
        {
            cout<<parent[v]<<"-"<<v<<"\t"<<graph[parent[v]][v]<<"\n";
        }
    }
}

int main()
{
    vector<vector<int>> graph =
    {
        { 0,  3,  2,  0, 0 },
        { 3,  0, 16, 12, 0 },
        { 2, 16,  0,  0, 5 },
        { 0, 12,  0,  0, 0 },
        { 0,  0,  5,  0, 0 }
    };

    PrimsMinimumSpanningTree(graph);

    return 0;
}

/************************
Time Complexity  : O(V*V)
Space Complexity : O(V)
*************************/