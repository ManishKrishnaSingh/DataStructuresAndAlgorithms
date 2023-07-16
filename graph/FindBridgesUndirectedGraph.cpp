#include <bits/stdc++.h>

using namespace std;

/************************************************************************************************
Find Bridges in a graph using Tarjan’s Algorithm: A bridge is a connection between two nodes that 
if removed, causes the network to become unconnected & thus increases the number of linked nodes.
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

    void dfs(int u, vector<bool>& visited, vector<int>& lowestTime, vector<int>& discoveryTime, int parent)
    {
        static int time = 0;

        visited[u] = true;

        discoveryTime[u] = lowestTime[u] = ++time;

        for(auto& v : adj[u])
        {
            if(v == parent)
            {
                continue;
            }

            if(visited[v])
            {
                lowestTime[u] = min(lowestTime[u], discoveryTime[v]);
            }
            else
            {
                parent = u;

                dfs(v, visited, lowestTime, discoveryTime, parent);

                lowestTime[u] = min(lowestTime[u], lowestTime[v]);

                if(lowestTime[v] > discoveryTime[u])
                {
                    cout << "{" << u << "," << v << "} ";
                }
            }
        }
    }

    void findBridges()
    {
        vector<bool> visited(V,false);	
        vector<int>  lowestTime(V,-1);
        vector<int>  discoveryTime(V,-1);
		
        int v, parent = -1;
        for(v = 0; v < V; v++)
        {
            if(!visited[v])
            {
                dfs(v, visited, lowestTime, discoveryTime, parent);
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

    cout<<"Bridges: ";
    graph.findBridges();

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/
