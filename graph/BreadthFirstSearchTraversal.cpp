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

    void breadthFirstSearch(int start){
        bool visited[V] = {false};

        list<int> queue;
        queue.push_back(start);

        visited[start] = true;
        list<int>::iterator iter;
        while(!queue.empty()){
            int front = queue.front();
            queue.pop_front();

            cout<<" "<<front;
            for(iter=adj[front].begin(); iter!=adj[front].end(); iter++){
                if (!visited[*iter]){
                    visited[*iter] = true;
                    queue.push_back(*iter);
                }
            }
        }
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

    cout<<"Breadth First Traversal:";
    graph.breadthFirstSearch(2);

    return 0;
}

