#include<bits/stdc++.h>

using namespace std;

/**pair{destination,time}*/
typedef pair<int,int> Node;

int networkDelayTime(vector<vector<int>>& times, int nodes, int start){
    int n = nodes + 1;

    // graph edge container
    vector<vector<Node>> edges(n);

    // add graph edges
    int src, dst, unt;
    for(auto edge : times){
        src = edge[0]; //source node
        dst = edge[1]; //target node
        unt = edge[2]; //travel time
        edges[src].push_back({dst, unt});
    }

    //find min cost
    bool visited[n];
    memset(visited,false,n);

    //create min heap with distance and edge end index
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push({0, start});

    int maxdelay=0;
    int delay, index;
    while(!pq.empty()){
        auto top=pq.top();pq.pop();
        delay = top.first;
        index = top.second;
        // if not visited
        if(!visited[index]){
            // mark visited
            visited[index] = true;
            // update max network delay
            maxdelay = max(delay, maxdelay);
            // visit connected edges
            for(auto node : edges[index]){
                if(!visited[node.first]){
                    pq.push({delay+node.second, node.first});
                }
            }
        }
    }

    //check if all nodes visited
    for(int i = 1; i < n; i++) {
        if(!visited[i]){
            maxdelay = -1;
        }
    }

    return maxdelay;
}

int main(){
    int nodes = 4, start = 2;
    vector<vector<int>> times = {
        {2,1,1}, {2,3,1}, {3,4,1}
    };

    int minTime = networkDelayTime(times, nodes, start);
    cout<<"Minimum Network Delay Time = "<<minTime<<"\n";

    return 0;
}
