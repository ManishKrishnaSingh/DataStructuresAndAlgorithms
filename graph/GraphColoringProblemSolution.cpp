#include <list>
#include <iostream>

using namespace std;

class Graph {
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
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }

    void applyColor(){
        int assigned[V];
        bool available[V];
        for(int i=0; i<V; i++){
            assigned[i] = -1;
            available[i] = true;
        }

        assigned[0] = 0;
        available[0] = false;

        for(int u=1; u<V; u++){
            for(auto iter=adj[u].begin(); iter!=adj[u].end(); iter++){
                if(assigned[*iter] != -1){
                    available[assigned[*iter]]=false;
                }
            }

            for(int color=0; color<V; color++){
                if(available[color]){
                    assigned[u] = color; break;
                }
            }

            for(auto iter=adj[u].begin(); iter!=adj[u].end(); iter++){
                if(assigned[*iter] != -1){
                    available[assigned[*iter]]=true;
                }
            }
        }

        cout<<"V ==> C"<<endl;
        for(int i=0; i<this->V; i++){
            cout<<i<<" ==> "<<assigned[i]<<endl;
        }
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.applyColor();

    return 0;
}

