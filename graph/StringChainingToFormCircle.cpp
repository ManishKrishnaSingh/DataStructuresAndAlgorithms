#include <bits/stdc++.h>

using namespace std;

/**********************************************************************
Eulerian Path is a path in a graph that visits every edge exactly once.
Eulerian Circuit is an Eulerian Path that starts & ends on same vertex. 
***********************************************************************/

class Graph
{
    int V;
    list<int> *adj;
    vector<int> in;

public:
    Graph(int iV): V(iV)
    {
        in.assign(V, 0);
        adj = new list<int>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        in[v]++;
    }

    bool IsEulerianCycle()
    {
        if (!IsStronglyConnected())
        {
            return false;
        }

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() != in[i])
            {
                return false;
            }
        }

        return true;
    }

    bool IsStronglyConnected()
    {
        vector<bool> visited(V,false);

        int n;
        for (n = 0; n < V; n++)
        {
            if (adj[n].size() > 0)
            {
                break;
            }
        }

        dfs(n, visited);

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0 && visited[i] == false)
            {
                return false;
            }
        }

        Graph graph=getTranspose();

        visited.assign(V, false);

        graph.dfs(n, visited);

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() > 0 && visited[i] == false)
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int u, vector<bool>& visited)
    {
        visited[u] = true;

        for (auto& v : adj[u])
        {
            if (!visited[v])
            {
                dfs(v, visited);
            }
        }
    }

    Graph getTranspose()
    {
        Graph graph(V);

        for(int u=0; u<V; u++)
        {
            for(auto& v : adj[u])
            {
                graph.adj[v].push_back(u);
                graph.in[u]++;
            }
        }

        return graph;
    }
};

bool IsPossibleToChain(vector<string>& arr)
{
    Graph graph(26);

    for(auto& str : arr)
    {
        if(!str.empty())
        {
            graph.addEdge(str[0] - 'a', str[str.length()-1] - 'a');
        }
    }

    return graph.IsEulerianCycle();
}

int main()
{
    vector<string> strList =
    {
        "for", "geek", "rig", "kaf"
    };

    if(IsPossibleToChain(strList))
    {
        cout<<"Strings can be chained to form a circle\n";
    }
    else
    {
        cout<<"Strings can't be chained to form a circle\n";
    }

    return 0;
}

/*****************************
Time Complexity  : O(N*M)
Space Complexity : O(max(N,M))
******************************/
