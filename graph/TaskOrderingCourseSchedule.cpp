#include <bits/stdc++.h>

using namespace std;

/***************************************************************************
Find the ordering of tasks from given dependencies
****************************************************************************
Degree of Vertex in a Graph:
	- Undirected Graph: Number of edges connected to the vertex V

	- Directed Graph: Each vertex has an indegree and an outdegree
		- Indegree  : Number of edges which are coming into the vertex V
		- Outdegree : Number of edges which are going out from the vertex V
****************************************************************************/

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int& iV): V(iV)
    {
        this->adj = new list<int>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int& u, int& v)
    {
        adj[u].push_back(v);
    }

    void computeIndegree(vector<int>& degrees)
    {
        int index;
        for(index=0; index<V; index++)
        {
            for(auto& neighbor : adj[index])
            {
                degrees[neighbor]++;
            }
        }
    }

    vector<int> findOrder()
    {
        int index, qFront;

        // vertices of 0 degree
        vector<int> degrees(V,0);
        computeIndegree(degrees);

        queue<int> qZeroDegree;
        for(index=0; index<V; index++)
        {
            if(degrees[index] == 0)
            {
                qZeroDegree.push(index);
            }
        }

        vector<int> sortTopological;
        for(index=0; index<V; index++)
        {
            if(qZeroDegree.empty())
            {
                return {};
            }

            qFront = qZeroDegree.front(); qZeroDegree.pop();

            sortTopological.push_back(qFront);

            for(int& neighbor : adj[qFront])
            {
                degrees[neighbor]--;

                if(degrees[neighbor] == 0)
                {
                    qZeroDegree.push(neighbor);
                }
            }
        }

        return sortTopological;
    }
};

int main()
{
    int numTasks = 4;

    vector<pair<int,int>> prerequisites =
    {
        {1, 0}, {2, 1}, {3, 2}
    };

    Graph graph(numTasks);
    for(auto& item : prerequisites)
    {
        graph.addEdge(item.second, item.first);
    }

    for (auto& Task : graph.findOrder())
    {
        cout << Task << " ";
    }

    return 0;
}

/************************
Time Complexity  : O(V+E)
Space Complexity : O(V)
*************************/
