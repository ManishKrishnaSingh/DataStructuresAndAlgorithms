#include <bits/stdc++.h>

using namespace std;

/**************************************************************************
A directed graph is strongly connected if there is a path between all pairs
of vertices.  A Strongly Connected Component (SCC) of a directed graph is a
maximal strongly connected subgraph.#Implementation using Kosaraju's algo
***************************************************************************/

class Graph
{
    int V;
    list<int> *adj;

    void sortTopological(int& u, vector<bool>& visit, stack<int>& stk)
    {
        visit[u] = true;
        for(auto& v : adj[u])
        {
            if(!visit[v])
            {
                sortTopological(v, visit, stk);
            }
        }
        stk.push(u);
    }

    void dfsPrint(int u, vector<bool>& visit)
    {
        visit[u] = true;
        cout << u << " ";
        for(auto& v : adj[u])
        {
            if(!visit[v])
            {
                dfsPrint(v, visit);
            }
        }
    }

public:
    Graph(int iV):V(iV)
    {
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    Graph getTranspose()
    {
        Graph reverseGraph(V);
        // Reverse or Transpose
        for (int u = 0; u < V; u++)
        {
            for(auto& v : adj[u])
            {
                reverseGraph.adj[v].push_back(u);
            }
		}
        return reverseGraph;
    }

    void PrintKosarajusSCCs()
	{
        vector<bool> visit(V, false);

        stack<int> stk;
        for(int u=0; u < V; u++)
        {
            if(!visit[u])
            {
                sortTopological(u, visit, stk);
            }
        }

        Graph reverseGraph = getTranspose();

        visit.assign(V, false);

        while(!stk.empty())
        {
            int u = stk.top(); stk.pop();
            if(!visit[u])
            {
                cout<<"\nStrongly Connected : ";
                reverseGraph.dfsPrint(u, visit);
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

    graph.PrintKosarajusSCCs();

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/