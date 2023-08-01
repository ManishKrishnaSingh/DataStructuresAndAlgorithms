#include <bits/stdc++.h>

using namespace std;

class DisjointSetUnion
{
    int* rank;
    int* parent;

public:
    DisjointSetUnion(int n)
    {
        rank = new int[n];
        parent = new int[n];
        for(int i=0; i<n; i++)
        {
            rank[i] = i;
            parent[i] = -1;
        }
    }

    int find(int x)
    {
        if(parent[x] == -1)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int pX = find(x);
        int pY = find(y);

        if(pX == pY)
        {
            return;
        }

        if(rank[pX] < rank[pY])
        {
            parent[pX] = pY;
        }
        else if(rank[pX] > rank[pY])
        {
            parent[pY] = pX;
        }
        else
        {
            parent[pY] = pX;
            rank[pX] = rank[pX] + 1;
        }
    }
};

struct Edge
{
    int start, finish, weight;
    Edge(int u, int v, int w)
    {
        this->start  = u;
        this->finish = v;
        this->weight = w;
    }
};

bool compare(const Edge& e1, const Edge& e2)
{
    if(e1.start != e2.start)
    {
        return e1.start < e2.start;
    }
    else if(e1.finish != e2.finish)
    {
        return e1.finish < e2.finish;
    }
    return e1.weight < e2.weight;
}

class Graph
{
    int V;
    vector<Edge> vEdge;

public:
    Graph(int iV):V(iV)
    {
        //TODO
    }

    ~Graph()
    {
        //TODO
    }

    void addEdge(int u, int v, int w)
    {
        vEdge.emplace_back(u,v,w);
    }

    int findMinimumCost()
    {
        sort(vEdge.begin(), vEdge.end(), compare);

        int minimumCost = 0;
        DisjointSetUnion dsu(V);

        for(Edge edge :  vEdge)
        {
            int& u = edge.start;
            int& v = edge.finish;
            int& w = edge.weight;
            if(dsu.find(u) != dsu.find(v))
            {
                dsu.Union(u, v);
                minimumCost = minimumCost+w;
                cout<<"Edge: "<<u<<" - "<<v<<"\n";
            }
        }

        return minimumCost;
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(3, 2, 4);
    graph.addEdge(2, 0, 2);
    graph.addEdge(0, 3, 2);
    graph.addEdge(1, 2, 2);

    int minCost = graph.findMinimumCost();
    cout << "Cost [MST]="<<minCost<<endl;

    return 0;
}
