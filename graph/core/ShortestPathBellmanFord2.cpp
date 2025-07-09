#include <bits/stdc++.h>

using namespace std;

void bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    for (int i = 0; i < V; i++) {

        for (vector<int> edge : edges) {
            int& u = edge[0];
            int& v = edge[1];
            int& w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {

                // If Vth relaxation, then it is a negative cycle
                if(i == V - 1) {
                    cout << "Negative Cycle";
                    return;
                }

                dist[v] = dist[u] + w;
            }
        }
    }

    // Shortest distances
    for(int i = 0; i < V; i++)
    {
        cout<<"["<<src<<","<<i<<"] = "<<dist[i]<<endl;
    }
}

int main() {
    int V = 5;

    //{source,destination,weight}
    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };

    bellmanFord(V, edges, 0);

    return 0; 
}