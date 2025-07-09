#include <bits/stdc++.h>

using namespace std;

/**********************************************************************
A mother vertex in a graph G = (V, E) is a vertex v such that all other
vertices in G can be reached by a path from v.
***********************************************************************/

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int iV): V(iV)
    {
        adj = new list<int>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u, vector<bool>& visited)
    {
        visited[u] = true;

        for(auto& v : adj[u])
        {
            if(!visited[v])
            {
                dfs(v, visited);
            }
        }
    }

    int findMotherVertex()
    {
        vector<bool> visited(V, false);

        int u, motherVertex=0;

        for(u=0; u < V; u++)
        {
            if(!visited[u])
            {
                dfs(u, visited);
                motherVertex = u;
            }
        }

        visited.assign(V, false);

        dfs(motherVertex, visited);

        for(u=0; u<V; u++)
        {
            if(!visited[u])
            {
                return -1;
            }
        }

        return motherVertex;
    }
};

int main()
{
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(4, 1);
    graph.addEdge(6, 4);
    graph.addEdge(5, 6);
    graph.addEdge(5, 2);
    graph.addEdge(6, 0);

    cout<<"Mother Vertex = "<<graph.findMotherVertex();

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/
