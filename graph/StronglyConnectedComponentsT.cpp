#include <bits/stdc++.h>

using namespace std;

/**************************************************************************
A directed graph is strongly connected if there is a path between all pairs
of vertices.  A Strongly Connected Component (SCC) of a directed graph is a
maximal strongly connected subgraph.#Implementation using Tarjans Algorithm
***************************************************************************/

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
    }

    void dfs(int u, vector<int>& lowValue, vector<int>& discoveryTime, stack<int>& stk, vector<bool>& InStack)
    {
        static int time = 0;

        stk.push(u);
        InStack[u] = true;

        discoveryTime[u] = lowValue[u] = ++time;

        for(auto& v : adj[u])
        {
            if(discoveryTime[v] == -1)
            {
                dfs(v, lowValue, discoveryTime, stk, InStack);

                lowValue[u] = min(lowValue[u], lowValue[v]);
            }
            else if(InStack[v])
            {
                lowValue[u] = min(lowValue[u], discoveryTime[v]);
            }
        }

        // To store stk extracted vertices
        if(lowValue[u] == discoveryTime[u])
        {
            int top;
            while(stk.top() != u)
            {
                top=stk.top();
                stk.pop();
                cout << top << " ";
                InStack[top]=false;
            }

            top=stk.top();
            stk.pop();
            cout << top <<"\n";
            InStack[top]=false;
        }
    }

    void PrintTarjansSCCs()
    {
        vector<int>  lowValue(V,-1);
        vector<int>  discoveryTime(V,-1);

        stack<int>   stk;
        vector<bool> InStack(V,false);

        for(int u = 0; u < V; u++)
        {
            if(discoveryTime[u] == -1)
            {
                dfs(u, lowValue, discoveryTime, stk, InStack);
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

    graph.PrintTarjansSCCs();

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/