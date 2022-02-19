#include <list>
#include <cstring>
#include <iostream>

using namespace std;

class Graph {
  private:
    int V;
    list<int> *adj;

  public:
    Graph(int V){
        this->V = V;
        this->adj = new list<int>[this->V];
    }

    ~Graph(){
        delete[] adj;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int,int> bfs(int src){
        int distance[this->V];
        memset(distance, -1, sizeof(distance));

        list<int> queue;
        queue.push_back(src);
        distance[src] = 0;

        while(!queue.empty()){
            int front = queue.front(); queue.pop_front();
            for(auto iter=adj[front].begin(); iter!=adj[front].end(); iter++){
                int v = *iter;
                if(distance[v] == -1){
                    queue.push_back(v);
                    distance[v] = distance[front]+1;
                }
            }
        }

        int maxDistance=0, index;
        for(int i=0; i<this->V; i++){
            if(distance[i] > maxDistance){
                index = i;
                maxDistance = distance[i];
            }
        }
        return make_pair(index, maxDistance);
    }

    int findLengthOfLongestPath(){
        pair<int,int> p1 = bfs(0);
        pair<int,int> p2 = bfs(p1.first);
        return p2.second;
    }
};

int main(){
    Graph graph(10);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 9);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);
    graph.addEdge(1, 6);
    graph.addEdge(6, 7);
    graph.addEdge(6, 8);

    int length = graph.findLengthOfLongestPath();
    cout<<"Length Of Longest Path = "<<length<<endl;

    return 0;
}

