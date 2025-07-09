#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

  public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void depthFirstSearchUtil(int v, bool visited[]){
        cout << " " << v;
        visited[v] = true;

        for(auto iter=adj[v].begin(); iter!=adj[v].end(); iter++){
            if (!visited[*iter]){
                depthFirstSearchUtil(*iter, visited);
            }
        }
    }

    void depthFirstSearch(int start){
        bool visited[V] = {false};
        depthFirstSearchUtil(start, visited);
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout<<"Depth First Traversal:";
    graph.depthFirstSearch(2);

    return 0;
}

