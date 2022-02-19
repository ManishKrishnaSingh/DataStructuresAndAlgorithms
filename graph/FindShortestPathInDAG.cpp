#include <list>
#include <stack>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct edge{
    int v, w;
    edge(int V, int W){
        this->v = V;
        this->w = W;
    }
}Edge;

class Graph{
    int V;
    list<Edge> *adj;

  public:
    Graph(int V){
        this->V = V;
        this->adj = new list<Edge>[V];
    }

    ~Graph(){
        delete [] adj;
    }

    void addEdge(int u, int v, int w){
        adj[u].emplace_back(v, w);
    }

    void topologicalSort(int v, bool visited[], stack<int>& stk){
        visited[v] = true;
        for(auto iter=adj[v].begin(); iter!=adj[v].end(); iter++){
            Edge edge = *iter;
            if(!visited[edge.v]){
                topologicalSort(edge.v, visited, stk);
            }
        }
        stk.push(v);
    }

    void ShortestPathLength(int start){
        bool visited[this->V];
        memset(visited, false, sizeof(visited));

        int distance[this->V];
        for(int i=0; i<this->V; i++){
            distance[i] = INT_MAX;
        }

        stack<int> stk;
        topologicalSort(start, visited, stk);

        distance[start] = 0;
        while(!stk.empty()){
            int top = stk.top(); stk.pop();
            if(distance[top] != INT_MAX){
                for(auto iter=adj[top].begin(); iter!=adj[top].end(); iter++){
                    if(distance[iter->v] > distance[top]+iter->w){
                        distance[iter->v] = distance[top] + iter->w;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++){
            if(start!=i && distance[i] != INT_MAX ){
                cout<<"Shortest Path Length ["<<start<<","<<i<<"] = "<<distance[i]<<endl;
            }
        }
    }
};

int main(){
    Graph graph(6);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 5, 1);
    graph.addEdge(3, 4, -1);
    graph.addEdge(4, 5, -2);

    graph.ShortestPathLength(1);

    return 0;
}

