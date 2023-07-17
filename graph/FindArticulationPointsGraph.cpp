#include <bits/stdc++.h>

using namespace std;

/************************************************************************************************
Articulation Points (or Cut Vertices) in a Graph: A vertex in an undirected connected graph is an
articulation point (or cut vertex) if removing it (and edges through it) disconnects the graph.
Articulation points represent vulnerabilities in a connected network – single points whose failure
would split the network into 2 or more components.
*************************************************************************************************/

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int iV): V(iV)
    {
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, vector<bool>& visited, vector<bool>& IsArticulationPoint, vector<int>& lowValue, vector<int>& discoveryTime, int parent)
    {
        static int time = 0;
 
        visited[u] = true;
 
        discoveryTime[u] = lowValue[u] = ++time;
 
        int children = 0; // no of children in dfs tree

        for(auto& v : adj[u])
        {
            if(!visited[v])
            {
                children++;

                dfs(v, visited, IsArticulationPoint, lowValue, discoveryTime, u);

                lowValue[u] = min(lowValue[u], lowValue[v]);

                if(parent != -1 && lowValue[v] >= discoveryTime[u])
                {
                    IsArticulationPoint[u] = true;
                }
            } 
            else if(v != parent)
            {
                lowValue[u] = min(lowValue[u], discoveryTime[v]);
            }
        }
 
        if (parent == -1 && children > 1)
        {
            IsArticulationPoint[u] = true;
        }
    }

    void findArticulationPoints()
    {
        vector<int>  lowValue(V,-1);
        vector<int>  discoveryTime(V,-1);

        vector<bool> visited(V,false);	
        vector<bool> IsArticulationPoint(V,false);	
		
        int u, parent = -1;
        for(u=0; u < V; u++)
        {
            if(!visited[u])
            {
				dfs(u, visited, IsArticulationPoint, lowValue, discoveryTime, parent);
            }
        }

        // Articulation Points
        for(u = 0; u < V; u++)
        {
            if(IsArticulationPoint[u])
            {
                cout << u << " ";
            }
        }
    }
};

int main()
{
    Graph graph(5);

    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);

    cout<<"Articulation Points: ";
    graph.findArticulationPoints();

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/
