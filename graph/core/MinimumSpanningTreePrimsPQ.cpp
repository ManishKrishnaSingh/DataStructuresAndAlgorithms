#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<pair<int,int>> *adj;

public:
    Graph(int iV):V(iV)
    {
        adj = new list<pair<int,int>>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void minSpanningTree()
    {
        vector<bool> visited(V, false);
        vector<int>  parent(V, -1);
        vector<int>  weight(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0}); // start with vertex "0"

        while(!pq.empty())
        {
            int u=pq.top().second; pq.pop();

            if(visited[u])
            {
                continue;
            }

            visited[u] = true;

            for(auto& pEntry : adj[u])
            {
                int& v = pEntry.first;
                int& w = pEntry.second;

                if (!visited[v] and weight[v] > w)
                {
                    parent[v] = u;
                    weight[v] = w;
                    pq.push({weight[v], v});
                }
            }
        }

        for (int v = 1; v < V; v++)
        {
            cout<<"Edge: "<<parent[v]<<" - "<<v<<endl;
        }
    }
};

int main()
{
    Graph graph(9);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    graph.minSpanningTree();

    return 0;
}

/****************************
Time Complexity  : O(ElogV))
Space Complexity : O(V)
*****************************/