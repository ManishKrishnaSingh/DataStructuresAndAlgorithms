#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

class DishointSetUnion {
    int* rank;
    int* parent;
  public:
    DishointSetUnion(int n){
        rank = new int[n];
        parent = new int[n];
        for(int i=0; i<n; i++){
            rank[i] = i;
            parent[i] = -1;
        }
    }

    int find(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int pX = find(x);
        int pY = find(y);

        if(pX == pY){
            return;
        }

        if(rank[pX] < rank[pY]){
            parent[pX] = pY;
        } else if(rank[pX] > rank[pY]){
            parent[pY] = pX;
        } else {
            parent[pY] = pX;
            rank[pX] = rank[pX] + 1;
        }
    }
};

typedef struct edge{
    int start, finish, weight;
    edge(int u, int v, int w){
        this->start  = u;
        this->finish = v;
        this->weight = w;
    }
}Edge;

bool compare(Edge e1, Edge e2){
    if(e1.start != e2.start){
        return e1.start < e2.start;
    } else if(e1.finish != e2.finish){
        return e1.finish < e2.finish;
    }
    return e1.weight < e2.weight;
}

class Graph{
    int V;
    vector<Edge> edges;

  public:
    Graph(int V){
        this->V = V;
    }

    ~Graph(){
        //TODO
    }

    void addEdge(int u, int v, int w){
        edges.emplace_back(u,v,w);
    }

    int findMinimumCost(){
        sort(edges.begin(), edges.end(), compare);

        int cost = 0;
        DishointSetUnion dsu(V);
        for(Edge edge :  edges){
            int u = edge.start;
            int v = edge.finish;
            int w = edge.weight;
            if(dsu.find(u) != dsu.find(v)){
                dsu.Union(u, v);
                cost = cost + w;
                cout<<"Edge : "<<u<<" - "<<v<<endl;
            }
        }
        return cost;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(3, 2, 4);
    graph.addEdge(2, 0, 2);
    graph.addEdge(0, 3, 2);
    graph.addEdge(1, 2, 2);

    int minCost = graph.findMinimumCost();
    cout << "Cost [MST]="<<minCost<<endl;

    return 0;
}

