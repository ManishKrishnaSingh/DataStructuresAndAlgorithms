#include <list>
#include <cstring>
#include <iostream>

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

	int find(int parent[], int index)
	{
	    if(parent[index] == -1)
	    {
	        return index;
	    }
	    return find(parent, parent[index]);
	}

	void Union(int parent[], int u, int v)
	{
	    parent[u] = v;
	}

	bool hasCycle()
	{
	    int parent[this->V];
	    memset(parent, -1, sizeof(parent));

	    list<Edge>::iterator it;
	    for(it=listOfEdge.begin(); it!=listOfEdge.end(); it++)
	    {
	        int x = find(parent, it->first);
	        int y = find(parent, it->second);

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

	cout<<"Graph has Cycle = "<<boolalpha<<graph.hasCycle();

	return 0;
}
