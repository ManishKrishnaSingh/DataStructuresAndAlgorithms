#include <climits>
#include <iostream>

using namespace std;

typedef struct edge{
    int start, finish, weight;
}Edge;

class Graph{
    int V, E;
    Edge *edge;
  public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        this->edge = new Edge[E];
    }

    ~Graph(){
        delete[] edge;
    }

    void addEdge(int index, int u, int v, int w){
        edge[index].start  = u;
        edge[index].finish = v;
        edge[index].weight = w;
    }

    void findShortestPath(int start){
        int distance[this->V];
        for(int i=0; i<this->V; i++){
            distance[i] = INT_MAX;
        }

        distance[start] = 0;

        for(int v=0; v<V; v++){
            for(int e=0; e<E; e++){
                int u = this->edge[e].start;
                int v = this->edge[e].finish;
                int w = this->edge[e].weight;
                if(distance[u]!=INT_MAX && distance[v] > distance[u]+w){
                    distance[v] = distance[u] + w;
                }
            }
        }

        //check for negative weight cycle
        for(int e=0; e<E; e++){
            int u = this->edge[e].start;
            int v = this->edge[e].finish;
            int w = this->edge[e].weight;
            if(distance[u]!=INT_MAX && distance[v] > distance[u]+w){
                cout<<"Negative Weight Cycle!"<<endl; return;
            }
        }

        for(int v=0; v<this->V; v++){
            cout<<"Shortest Path ["<<start<<","<<v<<"] = "<<distance[v]<<endl;
        }
    }
};

int main(){
    Graph graph(5, 8);

    graph.addEdge(0, 0, 1,-1);
    graph.addEdge(1, 0, 2, 4);
    graph.addEdge(2, 1, 2, 3);
    graph.addEdge(3, 1, 3, 2);
    graph.addEdge(4, 1, 4, 2);
    graph.addEdge(5, 3, 2, 5);
    graph.addEdge(6, 3, 1, 1);
    graph.addEdge(7, 4, 3,-3);

    graph.findShortestPath(0);

    return 0;
}

/****************************
Time Complexity  : O(V.E))
Space Complexity : O(V)
*****************************/
