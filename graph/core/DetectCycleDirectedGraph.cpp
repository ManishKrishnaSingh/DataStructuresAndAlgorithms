#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Edge;

class Graph
{
	int V;
	list<Edge> listOfEdge;

public:
	Graph(int V)
	{
		this->V = V;
	}

	void addEdge(int src, int dst)
	{
		listOfEdge.push_back({src, dst});
	}

	int find(vector<int>& parent, int index)
	{
	    if(parent[index] == -1)
	    {
	        return index;
	    }
	    return find(parent, parent[index]);
	}

	void Union(vector<int>& parent, int u, int v)
	{
	    parent[u] = v;
	}

	bool hasCycle()
	{
	    vector<int> parent(V, -1);
	    for(auto& edge : listOfEdge)
	    {
	        int x = find(parent, edge.first);
	        int y = find(parent, edge.second);

	        if(x == y)
	        {
	            return true;
	        }

	        Union(parent, x, y);
	    }
	    return false;
	}
};

int main()
{
	Graph graph(3);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);

	cout<<"Graph has Cycle ? "<<boolalpha<<graph.hasCycle();

	return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/