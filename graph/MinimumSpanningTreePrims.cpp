#include <list>
#include <queue>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<int,int> Node;

class Graph{
    int V;
    list<pair<int,int>> *adj;

  public:
    Graph(int V){
        this->V = V;
        this->adj = new list<pair<int,int>>[V];
    }

    ~Graph(){
        delete[] adj;
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    void minimumSpanningTree(){
        priority_queue<Node,vector<Node>,greater<Node>> pQueue;

        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inmst(V, false);

        int start = 0;
        pQueue.push({0, start});

        while(!pQueue.empty()){
            int u=pQueue.top().second;
            pQueue.pop();

            if(inmst[u] == true){
                continue;
            } else {
                inmst[u] = true;
            }

            for (auto iter=adj[u].begin(); iter!=adj[u].end(); iter++){
                int v = iter->first;
                int w = iter->second;

                if (inmst[v]==false && key[v]>w){
                    key[v] = w;
                    parent[v] = u;
                    pQueue.push(make_pair(key[v], v));
                }
            }
        }

        for (int v=1; v<V; v++){
            cout<<"Edge: "<<parent[v]<<" - "<<v<<endl;
        }
    }
};

int main(){
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

    graph.minimumSpanningTree();

    return 0;
}

