#include <bits/stdc++.h>

using namespace std;

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

private:
    bool dfsIsCyclic(int u, vector<bool>& visit, int parent)
    {
        visit[u] = true;
        for(auto& v : adj[u])
        {
            if(!visit[v])
            {
                if(dfsIsCyclic(v, visit, u))
                {
                    return true;
                }
            }
            else if(v != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool hasCycle()
    {
        vector<bool> visit(V,false);
        for(int u = 0; u < V; u++)
        {
            if(!visit[u])
            {
                if(dfsIsCyclic(u, visit, -1))
                {
                    return true;
                }
            }
        }
        return false;
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

	cout<<"Graph has Cycle ? "<<boolalpha<<graph.hasCycle();

    return 0;
}