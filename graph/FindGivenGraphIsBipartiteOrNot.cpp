#include <bits/stdc++.h>

using namespace std;

/*********************************************************************************************
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V
such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U.
In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and
v to U. We can also say that there is no edge that connects vertices of same set.
**********************************************************************************************/

bool IsBipartite(vector<vector<int>>& graph, int src)
{
    if(graph.size() == 0 || graph[0].size() == 0)
    {
        return false;
    }

    int V = graph.size();

    vector<int> assignedColor(V, -1);

    // assign color to src
    assignedColor[src] = 1;

    queue<int> gQueue;
    gQueue.push(src);

    int u, v;
    while(!gQueue.empty())
    {
        u = gQueue.front(); gQueue.pop();

        // check self loop
        if(graph[u][u] == 1)
        {
            return false;
        }

        for(v = 0; v < V; v++)
        {
            if(graph[u][v] == 1)
            {
                if(assignedColor[v] == -1)
                {
                    assignedColor[v] = 1 - assignedColor[u];
                    gQueue.push(v);
                }
                else if(assignedColor[v] == assignedColor[u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> graph =
    {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    cout<<"Is Bipartite ? "<<boolalpha<<IsBipartite(graph, 0);

    return 0;
}

/************************
Time Complexity  : O(V^2)
Space Complexity : O(V)
*************************/