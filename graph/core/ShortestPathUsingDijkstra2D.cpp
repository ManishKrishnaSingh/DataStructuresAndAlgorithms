#include <bits/stdc++.h>

using namespace std;

int minIndexByDistance(vector<int>& distance, vector<bool>& visited, int V)
{
    int minIndex, minValue=INT_MAX;
    for(int v = 0; v < V; v++)
    {
        if(!visited[v] and minValue >= distance[v])
        {
            minIndex = v;
            minValue = distance[v];
        }
    }
    return minIndex;
}

void DijkstraShortestPath(vector<vector<int>>& graph, int start)
{
    if(graph.size()==0 || graph[0].size()==0)
    {
        return;
    }

    int V = graph.size();

    vector<bool> visited(V,false);
    vector<int> distance(V,INT_MAX);

    distance[start] = 0;
    for(int counter=0; counter < V; counter++)
    {
        int u = minIndexByDistance(distance, visited, V);

        visited[u] = true;

        if(distance[u] != INT_MAX)
        {
            for(int v = 0; v < V; v++)
            {
                if(!visited[v] and graph[u][v] and distance[v] > (distance[u]+graph[u][v]))
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    for(int v = 0; v < V; v++)
    {
        cout<<"Shortest Path ["<<start<<","<<v<<"] = "<<distance[v]<<endl;
    }
}

int main()
{
    vector<vector<int>> graph =
    {
        { 0, 4,  0,  0,  0,  0, 0,  8, 0 },
        { 4, 0,  8,  0,  0,  0, 0, 11, 0 },
        { 0, 8,  0,  7,  0,  4, 0,  0, 2 },
        { 0, 0,  7,  0,  9, 14, 0,  0, 0 },
        { 0, 0,  0,  9,  0, 10, 0,  0, 0 },
        { 0, 0,  4, 14, 10,  0, 2,  0, 0 },
        { 0, 0,  0,  0,  0,  2, 0,  1, 6 },
        { 8, 11, 0,  0,  0,  0, 1,  0, 7 },
        { 0, 0,  2,  0,  0,  0, 6,  7, 0 }
    };

    DijkstraShortestPath(graph, 0);

    return 0;
}

/************************
Time Complexity  : O(V*V)
Space Complexity : O(V)
*************************/
