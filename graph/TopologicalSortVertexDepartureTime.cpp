#include <list>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

class Graph{
  private:
    int V;
    list<int> *adj;
  public:
    Graph(int V){
        this->V = V;
        this->adj = new list<int>[V];
    }

    ~Graph(){
        delete[] adj;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void topologicalSort(){
        bool visited[this->V];
        memset(visited, false, sizeof(visited));

        int time = 0;
        int departure[this->V];
        memset(departure, -1, sizeof(departure));

        for(int i=0; i<this->V; i++){
            if(!visited[i]){
                topologicalSortUtil(i, visited, departure, time);
            }
        }

        cout<<"Topological Sort:";
        for(int i=0; i<this->V; i++){
            cout<<" "<<departure[i];
        }
        cout<<endl;
    }

    void topologicalSortUtil(int v, bool visited[], int departure[], int& time){
        visited[v] = true;
        for(auto iter=adj[v].begin(); iter!=adj[v].end(); iter++){
            if(!visited[*iter]){
                topologicalSortUtil(*iter, visited, departure, time);
            }
        }
        departure[time++] = v;
    }
};

int main(){
    Graph graph(6);

    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.topologicalSort();

    return 0;
}

